from signal import signal, SIGINT
from sys import stdout, exit
import os
from abc import ABC, abstractmethod


class CommandOptionList():
    def __init__(self, optionNames: list):
        self.optionNames = optionNames

    def __str__(self):
        return self.optionNames[0]
    def __repr__(self):
        return self.optionNames[0]

class CommandParameter():
    def __init__(self, name: str, options: list):
        self.name = name
        self.options = options

    def __str__(self):
        return f'<{self.name}> -> [{", ".join([str(option) for option in self.options])}]'
    

class CommandParameterList():
    def __init__(self, parameters: list):
        self.parameters = parameters

    def __iter__(self):
        return iter(self.parameters)

class Command:
    def __init__(self, name: str, parameter_list: CommandParameterList):
        self.name = name
        self.parameter_list = parameter_list

    def __str__(self):
        return ' '.join([self.name] + [f'<{parameter.name}>' for parameter in self.parameter_list])
    def __repr__(self):
        output = ' '.join([self.name] + [f'<{parameter.name}>' for parameter in self.parameter_list])
        for parameter in self.parameter_list:
            output += f'\n  {str(parameter)}'
        return output

class CommandList:
    def __init__(self, commands: list):
        self.commands = commands

    def __getitem__(self, i):
        return self.commands[i]
    def __iter__(self):
        return iter(self.commands)

    def __str__(self):
        return '\n'.join([str(command) for command in self.commands])
    def __repr__(self):
        return '\n'.join([repr(command) for command in self.commands])

def signal_handler(sig, frame):
    exit()

def main():
    signal(SIGINT, signal_handler)

    commands = CommandList([
        Command('orbit', CommandParameterList([
            CommandParameter('type', [
                CommandOptionList(['low', 'leo']),
                CommandOptionList(['med', 'medium', 'meo']),
                CommandOptionList(['geo', 'geostationary', 'gso']),
                CommandOptionList(['pol', 'polar', 'gso'])
            ])
        ])),
        Command('dock', CommandParameterList([
            CommandParameter('location', [
                CommandOptionList(['low', 'leo']),
                CommandOptionList(['med', 'medium', 'meo']),
                CommandOptionList(['geo', 'geostationary', 'gso']),
                CommandOptionList(['pol', 'polar', 'gso'])
            ])
        ]))
    ])
    print(commands)


if __name__ == '__main__':
    main()
