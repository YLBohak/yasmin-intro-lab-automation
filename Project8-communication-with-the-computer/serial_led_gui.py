import PySimpleGUI as sg
import serial

#This script should be run only after burning sketch: serial_led to the arduino

#Connect with arduino. change port if insert arduino into different USB port.
arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1) 

#This dictionary stores the response to print to screen based on input from the arduino
response_ar = {'0': 'LED off','1':'button and LED on','2':'button off'}

def main():
    # All the stuff inside your window.
    layout = [  [sg.Text("How long would you like the led to remain on? (answer in ms)")],
            [sg.InputText(size=(30, 10))],
            [sg.Button('Ok')],
            [sg.Button('Clear Output')],
            [sg.Output(size=(30, 10))]]

    # Create the Window
    window = sg.Window('Led timed turn-off', layout)

    ########
    window.start_thread(lambda : write_read(window),'-thread-ended-')

    # Event Loop to process "events" and get the "values" of the inputs
    while True:
        # Constantly read events and values given by user
        event, values = window.read()
        # if user closes window, close window
        if event == sg.WIN_CLOSED:
            break

        #if event == 'Clear Output':

        #If user wants us to process his/her input
        if event == 'Ok':
            if not values[0].isnumeric():
                print('wrong input type, please enter number [s]')
            else:
                print('thank you for you input', values[0], '[ms]')
                #Send to the arduino here
                arduino.write(bytes(values[0], 'utf-8')) 
            
       
        if event == 'Serial':
            print(response_ar[str(values['Serial'])])

    
    window.close()


def write_read(window): 
    while True:
        #This line reads the input from the arduino 
        '''Wanto add  a lne that ys'''
        bytesWaiting = arduino.inWaiting() 
        
        if bytesWaiting > 0: 
            ar_res = arduino.read(bytesWaiting).decode().rstrip()
            #print(ar_res)
            if ar_res.isnumeric():
                #ar_res = int(ar_res)
                #This line generates an event that can be read by window.read() in the main section of the code
                #Serial is the event name that we gave, ar_res is a variable that stores the arduino response
                window.write_event_value('Serial',ar_res)
	   



if __name__ == "__main__":
    main()