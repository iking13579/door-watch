import serial
from datetime import datetime


with open("log.txt", "a") as f:
    while True:
        line = ser.readline().decode().strip()
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_line = f"{timestamp} - {line}"
        print(log_line)
        f.write(log_line + "\n")
