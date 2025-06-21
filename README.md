# Arduino Door Logger

This project monitors up to two doors using an Arduino and logs when each door is opened or closed. A connected Python script reads the Arduino's serial output, adds timestamps, and saves the log to a text file.

## 🛠 Hardware Requirements

- Arduino (Uno, Nano, etc.)
- 2x door sensors (e.g. magnetic reed switches)
- Jumper wires
- Optional: Pull-down resistors (or use `INPUT_PULLUP`)

## 🔌 Wiring

| Door | Arduino Pin |
|------|--------------|
| Door 1 | D2          |
| Door 2 | D3          |

Sensors should be wired to short the pin to GND when the door is closed. `INPUT_PULLUP` is used, so the default state is HIGH (door open).

## 📦 Arduino Code

The Arduino sketch reads two digital inputs (pins 2 and 3) and prints messages when door states change.

[Arduino sketch is in `arduino_door_logger.ino`](arduino_door_logger.ino)

## 💻 Python Script

The Python script does the following:

- Connects to the Arduino via USB (serial)
- Reads door state messages
- Adds a timestamp
- Prints the message to the terminal
- Logs it to `door_log.txt`

### Install Dependencies

```bash
python3 -m venv venv
source venv/bin/activate
pip install pyserial
