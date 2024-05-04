import numpy as np

class Versor:
    def __init__(self):
        self.q = np.array([1,0,0,0])
    def __init__(self, angle, axis):
        axis /= np.linalg.norm(axis)
        self.q = np.array({
            np.cos(angle),
            np.sin(angle) * axis[0],
            np.sin(angle) * axis[1],
            np.sin(angle) * axis[2],
        })
    def __init__(self, q):
        self.q = q / np.linalg.norm(q)
    def __init__(self, w, i, j, k):
        q = np.array([w,i,j,k])
        self.q = q / np.linalg.norm(q)
    
    def inv(self):
        return Versor(
             self.q[0],
            -self.q[1],
            -self.q[2],
            -self.q[3]
        )