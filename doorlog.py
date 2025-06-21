import serial
from datetime import datetime

# Replace '/dev/ttyUSB0' with your actual Arduino serial port
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)

log_file = "door_log.txt"

with open(log_file, "a") as f:  # Open log file for appending
    print("Starting to read from serial...")
    while True:
        line = ser.readline().decode('utf-8').strip()  # Read a line from serial
        if line:
            timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            log_line = f"{timestamp} - {line}"
            print(log_line)          # Print to shell
            f.write(log_line + "\n") # Write to file
            f.flush()               # Flush to make sure it writes immediately


