from pose import *
from math import pi





def main():
    p1 = Pose()
    p2 = Pose( pos_vel=[-1,2,0], rot_axis=[0,1,1], rot_vel=pi/3)
    
    print(p1.rel_pos(p2, 1))
    print(p1.rel_vel(p2, 4))
    print(p1.rel_ori(p2, 7))

if __name__ == '__main__':
    main()