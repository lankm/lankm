#ifndef PYSICS_GUARD_H
#define PYSICS_GUARD_H

#include <cstdint>
#include <array>
#include <algorithm>
#include "number.cpp"

#define DIMS 3
#define POSITION std::array<int64_t,DIMS>
#define VELOCITY std::array<int32_t,DIMS>
#define TIME uint32_t

class Translation {
    private:
        POSITION pos;
        VELOCITY vel;
        TIME time;

        /* returns current position in global coordinate frame */
        POSITION get_cur_pos(TIME now) {
            // initialize with original position
            POSITION p;
            std::copy(std::begin(this->pos), std::end(this->pos), std::begin(p));

            // calculate current position due to velocity
            TIME dt = now - this->time;
            for(int i = 0; i < DIMS; i++) {
                // static cast to preserve precision
                p[i] += static_cast<int64_t>(this->vel[i]) * dt;
            }

            return p;
        }
        /* updates current position */
        void update(TIME now) {
            if(this->time != now) {
                this->pos = this->get_cur_pos(now);
                this->time = now;
            }
        }
    public:
        /* applies an instant accelertion of dv */
        void accelerate(VELOCITY dv, TIME now) {
            // update position before velocity changes
            this->update(now);

            // change velocity by dv
            for(int i = 0; i < DIMS; i++) {
                this->vel[i] += dv[i];
            }
        }

        /* returns difference in position in global coordinate frame */
        POSITION get_rel_pos(Translation& other, TIME now) {
            // update this's position to current time
            this->update(now);
            other.update(now);

            // initialize with this's current position
            POSITION p;
            std::copy(std::begin(this->pos), std::end(this->pos), std::begin(p));

            // subtract other's current position
            for(int i = 0; i < DIMS; i++) {
                p[i] -= other.pos[i];
            }

            return p;
        }
        /* returns difference in velocity in global coordinate frame */
        VELOCITY get_rel_vel(Translation& other) {
            // initialize with this's velocity
            VELOCITY v;
            std::copy(std::begin(this->vel), std::end(this->vel), std::begin(v));

            // subtract other's velocity
            for(int i = 0; i < DIMS; i++) {
                v[i] -= other.vel[i];
            }

            return v;
        }
        
        // TODO find a way to allow construction for initial config but not while sim is running
        Translation() {
            this->pos = {0,0,0};
            this->vel = {0,0,0};
            this->time = 0;
        }

        // TODO make this better formatted
        friend std::ostream& operator<<(std::ostream& os, const Translation& obj) {
            for(auto &dim: obj.pos) {
                os << dim << ' ';
            }

            return os;
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

class Object {
    /* 
     * mass
     * translation
     * 
     * x,y,z moment of inertia
     * rotation
     */
};

#endif
