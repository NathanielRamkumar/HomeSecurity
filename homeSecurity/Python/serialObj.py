import serial
import time 

class SerialConn:

    arduino = serial.Serial(write_timeout=0.1) # Creates Serial Object

    # Settings for serial port
    def __init__(self, port='COM5', baudrate=9600): 
        self.arduino.port = port
        self.arduino.baudrate = 9600
        self.arduino.open()
        time.sleep(2)
        print("Connection Established")
    
    # Gets msg and parses it
    def waitSus(self): 
        return (self.arduino.read(3)).decode()
    
    def sendMessage(self,msg):
        self.arduino.write(msg.encode())


    # Closes serial connect (put at end of code)
    def exit(self):
        self.arduino.close()
