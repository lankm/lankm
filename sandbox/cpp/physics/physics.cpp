#include <cstdint>
#include "number.cpp"

class Translation {
    private:
        int64_t pos[3];
        int32_t vel[3];
        uint32_t time;

        void update() {

        }
    public:
        void get_rel_pos() {

        }
        void get_rel_vel() {
            
        }
};

class Rotation {
    private:
        Quaternion ori;
        Unit rot[3];
        Angle vel;
        uint32_t time;
        
        void update() {

        }
    public:
        void get_rel_ori() {

        }
        void get_rel_rot() {
            
        }
        void get_vel() {

        }
};
