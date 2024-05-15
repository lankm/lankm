from signal import signal, SIGINT
from sys import stdout, exit
import os


history = None
def load_from(file_name):
    global history
    input_file = open(file_name, 'r')
    history = input_file.read()
    stdout.write(history)
def save_to(file_name):
    global history
    output_file = open(file_name, 'w')
    output_file.write(history)

def terminal_start():
    stdout.write('\033[s') # save cursor location
    stdout.flush()

def terminal_end():
    stdout.write('\033[u') # move to original location
    stdout.write('\033[0J') # clear remaining screen
    stdout.flush()

def signal_handler(sig, frame):
    global running
    running = False

running = True
def main():
    signal(SIGINT, signal_handler)
    terminal_start()

    load_from('load.txt')

    while running:
        try:
            global history
            history += input() + '\n'
        except EOFError as e:
            pass

    save_to('load.txt')

    terminal_end()
    exit()

if __name__ == '__main__':
    main()
