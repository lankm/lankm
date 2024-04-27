import numpy as np

class Sphere:
    def __init__(self, pos, vel, r):
        self.pos = np.array(pos)
        self.vel = np.array(vel)
        self.r = r

def main():
    # defining objects
    s1 = Sphere([-1.11,-1.36,0],[1.164,-0.055,0],0.25)
    s2 = Sphere([ 0.7, -1.61,0],[0.53,  0.434,0],1)

    dp = s1.pos - s2.pos
    dv = s1.vel - s2.vel
    r = (s1.r + s2.r)**2

    pp = dp@dp
    pv = dp@dv
    vv = dv@dv

    discriminant = pv**2 - vv*(pp - r)
    if discriminant < 0:
        print("Will not collide")
    else:
        t = (-pv - np.sqrt(discriminant))/vv
        print(f'Will collide in {t} seconds.')

if __name__ == '__main__':
    main()