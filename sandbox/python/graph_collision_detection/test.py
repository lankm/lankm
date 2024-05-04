from pose import *
from math import pi
from time import sleep




def main():
    p1 = Pose()
    p2 = Pose( pos_vel=[-1,2,0], rot_axis=[0,1,1], rot_vel=pi/3)
    
    for i in range(1000000):
        p2.update(i)

if __name__ == '__main__':
    main()