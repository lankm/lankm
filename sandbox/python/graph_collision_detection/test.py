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
    q00 = q[0]*q[0]
    q01 = q[0]*q[1]
    q02 = q[0]*q[2]
    q03 = q[0]*q[3]
    q11 = q[1]*q[1]
    q12 = q[1]*q[2]
    q13 = q[1]*q[3]
    q22 = q[2]*q[2]
    q23 = q[2]*q[3]
    q33 = q[3]*q[3]
    res2[0] = p[0]*(+ q00 + q11 - q22 - q33) + 2*(p[1]*(+ q12 - q03) + p[2]*(+ q13 + q02))
    res2[1] = p[1]*(+ q00 - q11 + q22 - q33) + 2*(p[0]*(+ q12 + q03) + p[2]*(+ q23 - q01))
    res2[2] = p[2]*(+ q00 - q11 - q22 + q33) + 2*(p[0]*(+ q13 - q02) + p[1]*(+ q23 + q01))
    print(res2)


    # optimized algorithm
    

if __name__ == '__main__':
    main()