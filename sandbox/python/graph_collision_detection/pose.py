import numpy as np

class Quaternion:
    def mul(a, b):
        # 16 mul, 12 add
        result = np.zeros(4)
        
        result[0] = a[0]*b[0] - a[1]*b[1] - a[2]*b[2] - a[3]*b[3]
        result[1] = a[0]*b[1] + a[1]*b[0] + a[2]*b[3] - a[3]*b[2]
        result[2] = a[0]*b[2] - a[1]*b[3] + a[2]*b[0] + a[3]*b[1]
        result[3] = a[0]*b[3] + a[1]*b[2] - a[2]*b[1] + a[3]*b[0]

        return result

    def rotate(q, p):
        # 19 mul, 21 add, 3 bitshift
        result = np.zeros(3)

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
        result[0] = p[0]*(+ q[0]*q[0] + q[1]*q[1] - q[2]*q[2] - q[3]*q[3]) + 2*(p[1]*(q[1]*q[2] - q[0]*q[3]) + p[2]*(q[0]*q[2] + q[1]*q[3]))
        result[1] = p[1]*(+ q[0]*q[0] - q[1]*q[1] + q[2]*q[2] - q[3]*q[3]) + 2*(p[0]*(q[1]*q[2] + q[0]*q[3]) + p[2]*(q[2]*q[3] - q[0]*q[1]))
        result[2] = p[2]*(+ q[0]*q[0] - q[1]*q[1] - q[2]*q[2] + q[3]*q[3]) + 2*(p[0]*(q[1]*q[3] - q[0]*q[2]) + p[1]*(q[0]*q[1] + q[2]*q[3]))

        return result

    def inv(a):
        return np.array([
            a[0],
            -a[1],
            -a[2],
            -a[3]
        ])

class Pose:
    def __init__(self, time=0, pos=[0,0,0], pos_vel=[0,0,0], ori=[1,0,0,0], rot_axis=[1,0,0], rot_vel=0):
        self.__time = time
        self.__pos = np.array(pos)
        self.__pos_vel = np.array(pos_vel)
        self.__ori = np.array(ori) / np.linalg.norm(ori)
        self.__rot_axis = np.array(rot_axis) / np.linalg.norm(rot_axis)
        self.__rot_vel = rot_vel

    def __glob_pos(self, time):
        dt = time - self.__time
        return self.__pos + dt*self.__pos_vel
    def __glob_ori(self, time):
        dt = time - self.__time
        rotation = dt*self.__rot_vel / 2 # divide by 2 due to quaternion math
        sin, cos = np.sin(rotation), np.cos(rotation)

        rotator = np.array([
            cos,
            sin*self.__rot_axis[0],
            sin*self.__rot_axis[1],
            sin*self.__rot_axis[2]
        ])

        return Quaternion.mul(rotator, self.__ori)
    def __update(self, time):
        self.__pos = self.__glob_pos(time)
        self.__ori = self.__glob_ori(time)
        print(np.linalg.norm(self.__ori))

        # renormalize due to precision errors
        qinvnorm = (1-np.dot(self.__ori, self.__ori))/2 + 1
        self.__ori *= qinvnorm

        self.__time = time

    def __glob_pos_diff(self, other, time):
        return other.__glob_pos(time) - self.__glob_pos(time)
    def __glob_vel_diff(self, other):
        return other.__pos_vel - self.__pos_vel

    def rel_pos(self, other, time):
        return np.array(Quaternion.rotate(
            Quaternion.inv(self.__glob_ori(time)),
            self.__glob_pos_diff(other, time)
        )[1:])
    def rel_ori(self, other, time):
        return Quaternion.mul(Quaternion.inv(self.__glob_ori(time)), other.__glob_ori(time))
    def rel_vel(self, other, time):
        return np.array(Quaternion.rotate(
            Quaternion.inv(self.__glob_ori(time)), 
            self.__glob_vel_diff(other)
        )[1:])
    