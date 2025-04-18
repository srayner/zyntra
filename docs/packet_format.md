# 📦 Zyntra Packet Format

## Overview

All data sent over the serial connection is structured into packets.  
Each packet has a consistent format that includes a header, a payload, and a checksum.

---

## Packet Structure

| Field          | Size (bytes) | Description                                                            |
| :------------- | :----------: | :--------------------------------------------------------------------- |
| Start Byte     |      1       | Constant `0xAA` — marks the beginning of a packet                      |
| Command Type   |      1       | Identifies the type of command (e.g., Move Servo, Digital Write, etc.) |
| Payload Length |      1       | Number of bytes in the payload                                         |
| Payload        |    0–255     | Optional data specific to the command                                  |
| Checksum       |      1       | XOR checksum of all bytes **after** Start Byte and **before** Checksum |

---

## Detailed Explanation

- **Start Byte (0xAA)**  
  Marks the beginning of a new packet. Always `0xAA`.

- **Command Type**  
  A single byte specifying the action to perform.  
  Examples:

  - `0x01` → Move Servo
  - `0x02` → Digital Write
  - etc.

- **Payload Length**  
  The number of bytes in the Payload field. If no payload, this value is `0`.

- **Payload**  
  Data specific to the command, such as servo ID and target position for a move command.

- **Checksum**  
  XOR of all bytes between Start Byte and Checksum (excluding Start Byte itself).

---

## Example Packet

Suppose we want to send a command to **Move Servo 3 to 90 degrees**:

| Field          | Example Value | Description                                    |
| :------------- | :------------ | :--------------------------------------------- |
| Start Byte     | `0xAA`        | Start of packet                                |
| Command Type   | `0x01`        | Move Servo                                     |
| Payload Length | `0x02`        | 2 bytes of payload                             |
| Payload        | `0x03 0x5A`   | Servo ID = 3, Angle = 90 (0x5A)                |
| Checksum       | `0x58`        | XOR of all previous fields (except Start Byte) |

### Packet Bytes (in order):

...
AA 01 02 03 5A 58
...

---

## Notes

- **Packet Size**  
  Minimum packet size is 4 bytes (Start + Command + Length (0) + Checksum).

- **Payload Size Limit**  
  Up to 255 bytes of payload.

- **Resynchronization**  
  If the receiver reads unexpected data, it should search for the next occurrence of the Start Byte (`0xAA`).

---

## ✅ Packet Integrity Rules

- Start Byte must be `0xAA`.
- Checksum must match calculation.
- Payload Length must match actual payload size.

---

## 📚 Future Extensions

This format is simple but allows for future features, such as:

- Optional packet IDs for response tracking.
- Encrypted or compressed payloads.
- Multi-packet transmission for larger data.

---
