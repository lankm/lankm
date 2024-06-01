from signal import signal, SIGINT
from sys import stdout, exit
import os
from abc import ABC, abstractmethod


class CommandOptionList():
    def __init__(self, optionNames: list):
        self.optionNames = optionNames

    def __getitem__(self, i):
        return self.optionNames[i]
    def __iter__(self):
        return iter(self.optionNames)

    def __str__(self):
        return str(self.optionNames)
    def __repr__(self):
        return str(self)

class CommandParameter():
    def __init__(self, name: str, options: list):
        self.name = name
        self.options = options

    def __str__(self):
        return f'<{self.name}> -> [{", ".join([option[0] for option in self.options])}]'
    def __repr__(self):
        return str(self)

class CommandParameterList():
    def __init__(self, parameters=[]):
        self.parameters = parameters

    def __getitem__(self, i):
        return self.parameters[i]
    def __iter__(self):
        return iter(self.parameters)

    def __str__(self):
        return '\n'.join([str(parameter) for parameter in self.parameters])
    def __repr__(self):
        return str(self)

class Command:
    def __init__(self, name: str, parameter_list=CommandParameterList()):
        self.name = name
        self.parameter_list = parameter_list

    def __str__(self):
        output = ' '.join([self.name] + [f'<{parameter.name}>' for parameter in self.parameter_list])
        for parameter in self.parameter_list:
            output += f'\n  {str(parameter)}'
        return output
    def __repr__(self):
        return str(self)

class CommandList:
    def __init__(self, commands: list):
        self.commands = commands

    def __getitem__(self, i):
        return self.commands[i]
    def __iter__(self):
        return iter(self.commands)

    def __str__(self):
        return '\n'.join([' '.join([command.name] + [f'<{parameter.name}>' for parameter in command.parameter_list]) for command in self.commands])
    def __repr__(self):
        return str(self)

def create_command_list() -> CommandList:
    return CommandList([
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
                CommandOptionList(['station'])
            ])
        ])),
        Command('land', CommandParameterList([
            CommandParameter('location', [
                CommandOptionList(['station'])
            ])
        ])),
        Command('warp', CommandParameterList([
            CommandParameter('location', [
                CommandOptionList(['station'])
            ]),
            CommandParameter('speed', [
                CommandOptionList(['slow']),
                CommandOptionList(['med']),
                CommandOptionList(['fast'])
            ])
        ])),
        Command('load', CommandParameterList([
            CommandParameter('filename', [
                CommandOptionList(['TODO']) # figure out how to add the ability for any input
            ])
        ])),
        Command('save', CommandParameterList([
            CommandParameter('filename', [
                CommandOptionList(['TODO']) # figure out how to not require input. (defaults to some name)
            ])
        ])),
        Command('quit'),
        Command('help', CommandParameterList([  # figure out how to add the list of commands after the fact
            CommandParameter('command', [
                CommandOptionList(['station'])
            ])
        ])),
    ])

def signal_handler(sig, frame):
    exit()

def main():
    signal(SIGINT, signal_handler)

    commands = create_command_list()
    print(commands)


if __name__ == '__main__':
    main()
