import PySimpleGUI as sg
import sys
from pymata4 import pymata4
import time

board = pymata4.Pymata4(com_port="COM4")

LED_PIN = 4
board.set_pin_mode_digital_output(LED_PIN)
BUTTON_PIN = 2 #6 shorted to 2
board.set_pin_mode_digital_input(BUTTON_PIN)

#Time for timer untill shut off
t = 5 





#arduino loop
while True:
    #read button and see if on
    on_off = board.digital_read(BUTTON_PIN)
    if on_off[0] == 1:
        print('Button is on')
        #led_timer.start()
        on_off = board.digital_write(LED_PIN,1)
        time.sleep(t)
        on_off = board.digital_write(LED_PIN,0)