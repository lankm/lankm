import time
import sys

# just a little script to show an loading bar animation of a space ship doing a flip and burn manuver

def main():
    p = 0
    v = 0
    a = .01

    end = 100
    while p < end:
        p += v
        v += a * (1 if 2*p < end else -1)

        line = loadingBar(int(p), end)
        sys.stdout.write(line.strip() + '\r')
        time.sleep(ms(5))

    print()

        
def ms(t):
    return t/1000

def loadingBar(i, total):
    output = ''

    output += '['
    for j in range(total):
        if j<i:
            output+='~'
        elif j==i:
            output+='>' if j < total/2 else '<'
        elif j>i:
            output+='-' if j != 2*i else '|'
    output += ']'

    return output


if(__name__ == '__main__'):
    main()
