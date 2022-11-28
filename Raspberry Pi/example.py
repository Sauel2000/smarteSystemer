from serial import Serial
import time

arduino = Serial(port="COM4", baudRate=9600, timeout=.1)

def write_read(x):
    arduino.write(bytes(x, "utf-8"))
    time.sleep(0.05)
    data = arduino.readline()
    return data

write_read("Example")
