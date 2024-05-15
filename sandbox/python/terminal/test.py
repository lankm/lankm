from signal import signal, SIGINT
from sys import stdout, exit
import os


def orbit(type):
    match type:
        case 'low' | 'leo':
            print('Set orbit to low orbit')
        case 'med' | 'medium' | 'meo':
             print('Set orbit to medium orbit')
        case 'geo' | 'geostationary' | 'gso':
            print('Set orbit to a geostationary orbit')
        case 'pol' | 'polar' | 'gso':
            print('Set orbit to polar')
        case _:
            print(f'{type} is not a valid orbit type')
            return False
    return True


def signal_handler(sig, frame):
    exit()

def main():
    signal(SIGINT, signal_handler)

    while True:
        command = input().lower().split()
        match command[0]:
            case 'orbit':
                if len(command) == 2:
                    orbit(command[1])
                elif len(command) > 2:
                    print(f'Too many parameters were given')
                else:
                    print(f'\'{command[0]}\' command requires a type')
            case 'warp':
                pass
            case 'land':
                pass
            case 'dock':
                pass
            
            case 'load':
                pass
            case 'save':
                pass
            case 'exit':
                pass
            case 'help':
                pass

if __name__ == '__main__':
    main()
