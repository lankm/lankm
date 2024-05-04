from pose import *
from math import pi
from time import sleep




def main():
    theta = 0.98724
    axis = [0.3,2,.7]
    axis /= np.linalg.norm(axis)
    sin, cos = np.sin(theta), np.cos(theta)
    q = np.array([
        cos,
        sin*axis[0],
        sin*axis[1],
        sin*axis[2]
    ])

    p = [1,0,0]

    # mathmatical definition
    res1 = Quaternion.mul(Quaternion.mul(q, [0,*p]), Quaternion.inv(q))[1:]
    print(res1)
    res2 = [0,0,0]
    res2[0] = p[0]*(+ q[0]*q[0] + q[1]*q[1] - q[2]*q[2] - q[3]*q[3]) + 2*(p[1]*(q[1]*q[2] - q[0]*q[3]) + p[2]*(q[0]*q[2] + q[1]*q[3]))
    res2[1] = p[1]*(+ q[0]*q[0] - q[1]*q[1] + q[2]*q[2] - q[3]*q[3]) + 2*(p[0]*(q[1]*q[2] + q[0]*q[3]) + p[2]*(q[2]*q[3] - q[0]*q[1]))
    res2[2] = p[2]*(+ q[0]*q[0] - q[1]*q[1] - q[2]*q[2] + q[3]*q[3]) + 2*(p[0]*(q[1]*q[3] - q[0]*q[2]) + p[1]*(q[0]*q[1] + q[2]*q[3]))
    print(res2)


    # optimized algorithm
    

if __name__ == '__main__':
    main()