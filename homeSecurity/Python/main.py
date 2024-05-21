import os
import time
from serialObj import SerialConn
from os import startfile

dirname = os.path.dirname(__file__)
filename = os.path.join(dirname, 'sounds/gangnamStyle.mp3')
                                 
arduino = SerialConn(baudrate=9600)

arduino.sendMessage("obama")

print(arduino.waitSus())

startfile(filename)

arduino.exit()


