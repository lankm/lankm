#ifndef NUMBER_GUARD_H
#define NUMBER_GUARD_H

#include <cstdint>
#include <iostream>
#include <cmath>
#include <iomanip>

#define BIT_ALIGN 30

/* fixed point represtion of a number between -1 to 1 */
class Unit {
    private:
        /* can hold values between -2 to 1.999... */
        int32_t val;
        
        /* raw val setter */
        Unit(int32_t num) {
            val = num;
        }

    public:
        /* defaults to 1 */
        Unit() {
            val = ((uint32_t)1 << BIT_ALIGN);
        }
        /* float -> Unit */
        Unit(double num) {
            val = num*Unit().val;
        }

        // TODO implement += -+ *= /+ operators
        /* simple addition */
        Unit operator+(const Unit& other) const {
            return Unit(val + other.val);
        }
        /* simple subtraction */
        Unit operator-(const Unit& other) const {
            return Unit(val - other.val);
        }
        /* fixed point multiplication */
        Unit operator*(const Unit& other) const {
            // multiply then shift right. Rounding implemented
            int64_t calc = ( (int64_t)val * (int64_t)other.val + (1<<(BIT_ALIGN-1))) >> BIT_ALIGN;
            return Unit( (int32_t)calc );
        }
        /* fixed point division */
        Unit operator/(const Unit& other) const {
            // shift left then divide
            int64_t calc = ( ((int64_t)val<<BIT_ALIGN) / (int64_t)other.val );
            return Unit( (int32_t)calc );
        }
        /* square root function passthrough */
        Unit operator-() const {
            return Unit(-val);
        }
        /* square root function passthrough */
        Unit sqrt()  {
            // squareroot then renormalize
            double calc = std::sqrt(val) / (1 << (BIT_ALIGN>>1));
            
            return Unit(calc);
        }
        
        /* convert to double */
        friend std::ostream& operator<<(std::ostream& os, const Unit& obj) {
            os << (double)obj.val / (double)Unit().val;
            return os;
        }
};

# define PI2 (uint64_t)1<<32
/* fixed point representation of an angle between 0 to 2pi */
class Angle {
    private:
        /*  */
        uint32_t ang;

    public:
        /*  */
        Angle() {
            ang = 0;
        }
        /*  */
        Angle(double theta) {
            double rem = fmod(theta, 2*3.1415926535897932384626);
            rem /= 2*3.1415926535897932384626;
            rem *= PI2;

            ang = (uint32_t)rem;
        }

        /*  */
        friend std::ostream& operator<<(std::ostream& os, const Angle& obj) {
            os << obj.ang;
            return os;
        }

};

/* represents a unit quaternion */
class Quaternion {
    private:
        /* simple array values of a quaternion */
        Unit q[4];

    public:
        /* defaults to <1,0,0,0> */
        Quaternion() {
            this->q[0] = Unit();
            this->q[1] = Unit(0.0);
            this->q[2] = Unit(0.0);
            this->q[3] = Unit(0.0);
        }

        /* raw data passthrough */
        Quaternion(double a, double b, double c, double d) : Quaternion(Unit(a), Unit(b), Unit(c), Unit(d)) {}
        Quaternion(Unit a, Unit b, Unit c, Unit d) {
            this->q[0] = a;
            this->q[1] = b;
            this->q[2] = c;
            this->q[3] = d;

            this->normalize();
        }

        // TODO implement *= operators
        /* right multiplication of quaterions */
        Quaternion operator*(const Quaternion& other) const {
            // start with blank quaternion
            Quaternion result = Quaternion();

            // multiplication based on quaternion rules
            result.q[0] = q[0]*other.q[0] - q[1]*other.q[1] - q[2]*other.q[2] - q[3]*other.q[3];
            result.q[1] = q[0]*other.q[1] + q[1]*other.q[0] + q[2]*other.q[3] - q[3]*other.q[2];
            result.q[2] = q[0]*other.q[2] - q[1]*other.q[3] + q[2]*other.q[0] + q[3]*other.q[1];
            result.q[3] = q[0]*other.q[3] + q[1]*other.q[2] - q[2]*other.q[1] + q[3]*other.q[0];

            // return final result
            return result.normalize();
        }

        /* returns the length of the quaternion */
        Unit rotate(Unit x, Unit y, Unit z) {
            Unit dot = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];
            return dot.sqrt();
            
        }

        /* returns the length of the quaternion */
        Unit norm() {
            Unit dot = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];
            return dot.sqrt();
            
        }
        /* returns the inverse of a */
        Quaternion inv() {
            return Quaternion(q[0], -q[1], -q[2], -q[3]);
        }
        
        
        /* normalizes the quaternion object */
        Quaternion& normalize() {
            Unit norm = this->norm();

            for(int i = 0; i < 4; i++) {
                q[i] = q[i] / norm;
            }

            return *this;
        }

        /* displays the raw values of the instance variables */
        friend std::ostream& operator<<(std::ostream& os, const Quaternion& obj) {
            os << '<';
            for(int i = 0; i < 4; i++) {
                os << obj.q[i] << ' ';
            }
            os << "\b>";

            return os;
        }
};

#endif
