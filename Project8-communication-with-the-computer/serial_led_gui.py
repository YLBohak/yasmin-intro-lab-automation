import PySimpleGUI as sg
import serial

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1) 

# All the stuff inside your window.
layout = [  [sg.Text("How long would you like the led to remain on? (answer in ms)")],
            [sg.InputText(size=(30, 10))],
            [sg.Button('Ok')],
            [sg.Output(size=(30, 10))]]

# Create the Window
window = sg.Window('Led timed turn-off', layout)

# Event Loop to process "events" and get the "values" of the inputs
while True:
    # Constantly read events and values given by user
    event, values = window.read()

    # if user closes window, close window
    if event == sg.WIN_CLOSED:
        break

    #If user wants us to process his/her input
    if event == 'Ok':
        if not values[0].isnumeric():
            print('wrong input type, please enter number [s]')
        else:
            print('thank you for you input', values[0], '[ms]')
            #Send to the arduino here
            arduino.write(bytes(values[0], 'utf-8')) 

    if event == 'Serial':
        
    


window.close()


def write_read(seconds): 
    #This line generates an event that can be read by window.read() in the main section of the code
    #Serial is the event name that we gave, ar_res is a variable that stores the arduino response
    window.write_event_value('Serial',ar_res)
	   


