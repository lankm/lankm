#ifndef PYSICS_GUARD_H
#define PYSICS_GUARD_H

#include <cstdint>
#include <array>
#include <algorithm>
#include "number.cpp"

// TODO typedef and move unit related to an other section
#define DIMS 3
#define POSITION std::array<int64_t,DIMS>
#define VELOCITY std::array<int32_t,DIMS>
#define TIME uint32_t

/* defines a position in the global refrence frame */
class Translation {
    private:
        POSITION pos; /* position vector of last update */
        VELOCITY vel; /* velocity vector */
        TIME time;    /* time of last update */

        /* returns current position in global coordinate frame */
        POSITION cur_pos(TIME now) {
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
                this->pos = this->cur_pos(now);
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

        /* returns L2 norm between two positions */
        double_t dist_to(Translation& other, TIME now) {
            // update this's position to current time
            this->update(now);
            other.update(now);
            
            // initialize difference vector to current position and subtract other
            POSITION diff;
            std::copy(std::begin(this->pos), std::end(this->pos), std::begin(diff));
            for(int i = 0; i < DIMS; i++) {
                diff[i] -= other.pos[i];
            }

            // calculate dot product
            double_t dist = 0.0;
            for(int i = 0; i < DIMS; i++) {
                double_t dp = static_cast<double_t>(diff[i]);
                dist += dp*dp;
            }
            
            // return L2 norm
            return sqrt(dist);
        }
        /* returns difference in position in global coordinate frame */
        POSITION pos_rel_to(Translation& other, TIME now) {
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
        VELOCITY vel_rel_to(Translation& other) {
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

        /* displays the raw values of the instance variables */
        friend std::ostream& operator<<(std::ostream& os, const Translation& obj) {
            os << "{pos: <";
            for(auto &pos_dim: obj.pos) {
                os << pos_dim << ' ';
            }
            os << "\b>, vel: <";
            for(auto &pos_dim: obj.vel) {
                os << pos_dim << ' ';
            }
            os << "\b>, time: <" << obj.time << ">}";

            return os;
        }
};

/* defines a orientation in the global refrence frame */
class Rotation {
    private:
        Quaternion ori; /* orientation quaternion of last update */
        Unit rot[3];    /* axis of rotation */
        Angle vel;      /* rotation rate */
        uint32_t time;  /* time of last update */
        
        void update() {

        }
    public:
        /* defaults to no rotation at start of time */
        Rotation() {
            // start with no rotation
            ori = Quaternion();

            // set unit vector to <1,0,0>
            rot[1] = Unit();
            for(int i = 1; i < DIMS; i++) {
                rot[i] = Unit(0.0);
            }

            // no rotational velocity
            vel = 0;

            // last updated at beginning of time
            time = 0;
        }

        void get_rel_ori() {

        }
        void get_rel_rot() {
            
        }
        void get_vel() {

        }

        // TODO
        friend std::ostream& operator<<(std::ostream& os, const Rotation& obj) {
            return os;
        }
};

/* defines both position and orientation in a relative reference frame */
class Pose {
    /* 
     * Translation
     * Rotation
     */
};

/* defines the newtonian physics of an object */
class Object {
    /* 
     * mass
     * x,y,z moment of inertia
     * pose
     */

    /* 
     * f = ma
     * τ = Ia
     * every action has an oposite and equal reaction
     */
};

#endif
