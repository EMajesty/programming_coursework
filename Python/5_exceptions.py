import sys

class NegativeError(Exception):
    pass

def giveYear():
    try:
        print('Give a year: ')
        year = int(input())
        if year < 0:
            raise NegativeError()
    except NegativeError:
        print('Year cannot be negative')
    except ValueError:
        print('Year must be in numbers')

giveYear()