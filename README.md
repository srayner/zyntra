# 📡 **Zyntra**

_Fast Command Control for Arduino Projects_

---

## ✨ Overview

**Zyntra** is a lightweight, flexible communication protocol for controlling microcontrollers (like Arduino) over a serial interface.  
It is designed for reliable, fast, and structured execution of commands such as servo movements, pin I/O, NeoPixel control, and system operations.

Zyntra provides a clean and efficient way to send compact command packets, with built-in error checking and easy parsing.

---

## 🚀 Features

- Fast and reliable serial communication
- Lightweight packet structure with checksum validation
- Support for:
  - Servo control (attach, move, detach)
  - Digital and analog I/O (read/write)
  - NeoPixel setup and control
  - System commands (ping, reset, version)
  - Configuration save/load (EEPROM)
- Designed for Arduino Nano, Uno, Mega (and compatible boards)
- Easy to extend with new command types

---

## 🛠 Packet Format

| Field      | Size (bytes) | Description                     |
| :--------- | :----------- | :------------------------------ |
| Start Byte | 1            | Always `0xAA`                   |
| Length     | 1            | Payload length (Command + Args) |
| Command ID | 1            | Command identifier              |
| Arguments  | n            | Command-specific arguments      |
| Checksum   | 1            | XOR of all previous bytes       |

Example packet to move a servo:

...
[0xAA] [0x03] [0x32] [pin] [position] [checksum]
...

---

## 📚 Command Groups

| Group    | Commands                                                     |
| :------- | :----------------------------------------------------------- |
| Setup    | Set pin mode, Servo attach, NeoPixel setup, Config save/load |
| Input    | Digital read, Analog read                                    |
| Output   | Digital write, Analog write, Servo move/detach               |
| System   | Ping, Reset, Get version                                     |
| (Future) | Debug, Extended hardware control                             |

---

## 📈 Roadmap

- [ ] Arduino library `ZyntraLib`
- [ ] PC/Host-side command sender (Python/C++)
- [ ] Optional binary framing (start/stop bytes)
- [ ] Advanced error handling
- [ ] Full documentation site

---

## 📄 License

This project is licensed under the MIT License.  
Feel free to use, modify, and share!

---

# ⚡ **Zyntra — Build Faster, Move Smarter.**
