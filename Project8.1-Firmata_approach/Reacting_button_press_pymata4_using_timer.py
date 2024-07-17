import PySimpleGUI as sg
import sys
from pymata4 import pymata4
import time
import threading

board = pymata4.Pymata4(com_port="COM4")

LED_PIN = 4
board.set_pin_mode_digital_output(LED_PIN)
BUTTON_PIN = 6 #We no longer need to short it as we are not using an arduino interrupt anymore

#lables defined to make accessing the different components of the aray data (see below)
CB_PIN_MODE = 0
CB_PIN = 1
CB_VALUE = 2
CB_TIME = 3

#Time for timer untill shut off
t = 5 

def led_off():
    print('Led is off')
    board.digital_write(LED_PIN,0)


def button_fun(data):
    #data[2] is the value on/off
    if data[CB_VALUE] == 1:
        print('Led is on')
        #led_timer.start()
        board.digital_write(LED_PIN,1)
        #Timer from the threading package is defined such that it can call a function directly 
        #when the defined time elapsed
        timer = threading.Timer(5.0, led_off)
        # Start the timer
        timer.start()


#Needs to be defined after the function used for the calback is defined. The callback uses a separate thread 
#for the function that is called, so we don't need to define it ourselves. 
#The callback is defined as part of the pymata4 package, such that the array data is returned.
#see: https://github.com/MrYsLab/pymata4/blob/master/examples/digital_input.py, def the_callback(data):
board.set_pin_mode_digital_input(BUTTON_PIN, callback=button_fun)

while True:
    #Add this "delay" in the loop so that while is interupted once in a while to avoid crashing.
    time.sleep(0.1)









