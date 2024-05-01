from math import cos, sin, pi, radians
import logging
def sign(num):
    if num < 0:
        return "-"
    else:
        return "+"

class Quaternion:
    def __init__(self, r, i, j, k):
        self.r = r
        self.i = i
        self.j = j
        self.k = k

    def __mul__(self, other):
        r1 = self.r
        i1 = self.i
        j1 = self.j
        k1 = self.k

        r2 = other.r
        i2 = other.i
        j2 = other.j
        k2 = other.k

        r = r1*r2 - i1*i2 - j1*j2 - k1*k2
        i = r1*i2 + i1*r2 + j1*k2 - k1*j2
        j = r1*j2 - i1*k2 + j1*r2 + k1*i2
        k = r1*k2 + i1*j2 - j1*i2 + k1*r2
        
        return Quaternion(r, i, j, k)
    
    def __abs__(self):
        return (self*self.inv()).r**(1/2)
    
    def unit(self):
        return Quaternion(1/abs(self),0,0,0)*self
    
    def inv(self):
        r = self.r
        i = self.i
        j = self.j
        k = self.k

        return Quaternion(r, -i, -j, -k)
    
    def __str__(self):
        r = self.r
        i = self.i
        j = self.j
        k = self.k
        return f'{r} {sign(i)} {abs(i)}i {sign(j)} {abs(j)}j {sign(k)} {abs(k)}k'
    def __repr__(self):
        r = self.r
        i = self.i
        j = self.j
        k = self.k
        return f'{r} {sign(i)} {abs(i)}i {sign(j)} {abs(j)}j {sign(k)} {abs(k)}k'

def main():
    theta = radians(45)/2
    pos = [cos(theta)] + [sin(theta),0,0]
    q1 = Quaternion(*pos)
    print(q1)
    pos = [cos(theta)] + [0,sin(theta),0]
    q1 = Quaternion(*pos)*q1
    print(q1)
    q2 = Quaternion(0,0,1,0).unit()
    print(q1*q2*q1.inv())

    x = Quaternion(0,1,0,0)

def bin(num, bits=16):
    bin = ''
    for i in range(bits):
        if i%4==0:
            bin += ' '
        bin += str(num >> i & 1)
    return bin[::-1]

def bit_test():
    num = 2**(8-2)
    print(bin(num))
    print(num)

    res = num*num>>6
    print(bin(res))
    print(res)

if __name__ == "__main__":
    bit_test()
