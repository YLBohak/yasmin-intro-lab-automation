import PySimpleGUI as sg
import sys
from pymata4 import pymata4
import time
import threading

board = pymata4.Pymata4(com_port="COM4")

LED_PIN = 4
board.set_pin_mode_digital_output(LED_PIN)
BUTTON_PIN = 6 #


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
    if data[CB_VALUE] == 1:
        print('Led is on')
        #led_timer.start()
        board.digital_write(LED_PIN,1)
        timer = threading.Timer(5.0, led_off)
        # Start the timer
        timer.start()



board.set_pin_mode_digital_input(BUTTON_PIN, callback=button_fun)

while True:
    time.sleep(0.1)









