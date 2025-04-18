# 📚 Zyntra Command List

This document describes all available Zyntra commands and their formats.

---

## 🔧 Setup Commands

| Command        | ID (Hex) | Arguments                                         | Description                    |
| :------------- | :------- | :------------------------------------------------ | :----------------------------- |
| Set Pin Mode   | 0x10     | Pin (uint8), Mode (uint8)                         | Set pin as INPUT, OUTPUT, etc. |
| Servo Attach   | 0x11     | Pin (uint8), MinPulse (uint16), MaxPulse (uint16) | Attach servo to pin            |
| Servo Detach   | 0x12     | Pin (uint8)                                       | Detach servo from pin          |
| NeoPixel Setup | 0x13     | Pin (uint8), Count (uint16)                       | Initialize NeoPixel strip      |

---

## 🔍 Input Commands

| Command      | ID (Hex) | Arguments   | Description                    |
| :----------- | :------- | :---------- | :----------------------------- |
| Digital Read | 0x20     | Pin (uint8) | Read HIGH/LOW from digital pin |
| Analog Read  | 0x21     | Pin (uint8) | Read analog value from pin     |

---

## 🔥 Output Commands

| Command            | ID (Hex) | Arguments                                             | Description              |
| :----------------- | :------- | :---------------------------------------------------- | :----------------------- |
| Digital Write      | 0x30     | Pin (uint8), Value (0 or 1)                           | Set digital pin HIGH/LOW |
| Analog Write       | 0x31     | Pin (uint8), Value (0-255)                            | Write PWM value          |
| Servo Move         | 0x32     | Pin (uint8), Position (0-180)                         | Move servo to angle      |
| NeoPixel Set Pixel | 0x33     | Pixel Index (uint16), R (uint8), G (uint8), B (uint8) | Set pixel color          |
| NeoPixel Show      | 0x34     | none                                                  | Push pixel data to strip |

---

## ⚙️ System Commands

| Command      | ID (Hex) | Arguments | Description                    |
| :----------- | :------- | :-------- | :----------------------------- |
| Ping         | 0x40     | none      | Test connection                |
| Get Version  | 0x41     | none      | Get firmware version           |
| System Reset | 0x42     | none      | Soft reset the Arduino         |
| Config Save  | 0x43     | none      | Save configuration to EEPROM   |
| Config Load  | 0x44     | none      | Load configuration from EEPROM |

---

## 🧪 Debug Commands _(Optional, Future)_

| Command       | ID (Hex) | Arguments                     | Description                     |
| :------------ | :------- | :---------------------------- | :------------------------------ |
| Debug Log     | 0x50     | String data (variable length) | Send debug message back to host |
| Memory Status | 0x51     | none                          | Return free RAM                 |

---

# 📦 Notes

- All multi-byte fields are **Little Endian** (low byte first).
- Checksum is a simple XOR of all previous bytes in the packet.
- Every packet must start with `0xAA` Start Byte.

---
