#ifndef NUMBER_GUARD_H
#define NUMBER_GUARD_H

#include <cstdint>
#include <iostream>
#include <cmath>
#include <iomanip>

/* fixed point represtion of a number between -1 to 1 */
class Unit {
    friend class Quaternion;

    private:
        /* bitshift constant */
        static const int32_t BIT_ALIGN = 30;
        /* addition required to cause bitshift to round instead of floor */
        static const int32_t ROUND = 1<<(BIT_ALIGN-1);
        /* definition of 1 for i32, i64, and i16 */
        static const int32_t ONE = 1<<BIT_ALIGN;
        static const int64_t ONE_UP = 1ll<<(BIT_ALIGN<<1);
        static const int16_t ONE_DOWN = 1<<(BIT_ALIGN>>1);

        /* can hold values between -2 to 1.999... */
        int32_t val;
        
        /* raw value constructors */
        Unit(int64_t num) : Unit ((int32_t)num) {}
        Unit(int32_t num) {
            val = num;
        }

        static int32_t to_i32(int64_t num) {
            return (num + ROUND)>>BIT_ALIGN;
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
            int64_t calc = ( (int64_t)val * (int64_t)other.val + ROUND) >> BIT_ALIGN;
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
            return Unit(-this->val);
        }
        /* square root function passthrough */
        Unit sqrt()  {
            // squareroot then renormalize
            double calc = std::sqrt(this->val) / ONE_DOWN;
            
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

        /* raw value constructors */
        Quaternion(int64_t a, int64_t b, int64_t c, int64_t d) : Quaternion(Unit(a),Unit(b),Unit(c),Unit(d)) {}
        Quaternion(int32_t a, int32_t b, int32_t c, int32_t d) : Quaternion(Unit(a),Unit(b),Unit(c),Unit(d)) {}
        Quaternion(Unit a, Unit b, Unit c, Unit d) {
            this->q[0] = a;
            this->q[1] = b;
            this->q[2] = c;
            this->q[3] = d;
        }

        /* simple dot product */
        int64_t dot() {
            int64_t dot = + q[0].val*(int64_t)q[0].val
                          + q[1].val*(int64_t)q[1].val
                          + q[2].val*(int64_t)q[2].val 
                          + q[3].val*(int64_t)q[3].val;
            return dot;
        }
        /* quick inverse square root */
        int32_t invnorm() {
            // calculate quick inverse norm. based on derivitive of x^(1/2) at x=1
            return Unit::to_i32( 
                (Unit::ONE_UP - this->dot()     // subtract one and invert
                >> 1)                           // divide by 2
                + Unit::ONE_UP                  // add one
            );
        }


    public:
        /* default of <1,0,0,0> */
        Quaternion() {
            this->q[0] = Unit(1<<Unit::BIT_ALIGN);
            this->q[1] = Unit(0);
            this->q[2] = Unit(0);
            this->q[3] = Unit(0);
        }
        /* user-friendly conversion */
        Quaternion(double a, double b, double c, double d) {
            double norm = sqrt( a*a + b*b + c*c + d*d );
            double base = (1<<Unit::BIT_ALIGN)/norm;

            this->q[0] = Unit((int32_t)(a*base));
            this->q[1] = Unit((int32_t)(b*base));
            this->q[2] = Unit((int32_t)(c*base));
            this->q[3] = Unit((int32_t)(d*base));
        }
        

        /* right multiplication of quaterions. no renormalization */
        Quaternion operator*(const Quaternion& other) const {
            // multiplication based on quaternion rules
            int32_t a = Unit::to_i32(  
                + q[0].val*(int64_t)other.q[0].val 
                - q[1].val*(int64_t)other.q[1].val 
                - q[2].val*(int64_t)other.q[2].val
                - q[3].val*(int64_t)other.q[3].val
            );

            int32_t b = Unit::to_i32(
                + q[0].val*(int64_t)other.q[1].val
                + q[1].val*(int64_t)other.q[0].val
                + q[2].val*(int64_t)other.q[3].val
                - q[3].val*(int64_t)other.q[2].val
            );

            int32_t c = Unit::to_i32(
                + q[0].val*(int64_t)other.q[2].val
                - q[1].val*(int64_t)other.q[3].val
                + q[2].val*(int64_t)other.q[0].val
                + q[3].val*(int64_t)other.q[1].val
            );

            int32_t d = Unit::to_i32(
                + q[0].val*(int64_t)other.q[3].val
                + q[1].val*(int64_t)other.q[2].val
                - q[2].val*(int64_t)other.q[1].val
                + q[3].val*(int64_t)other.q[0].val
            );
  
            return Quaternion(a,b,c,d);
        }

        /* right multiplication of quaterions. with renormalization */
        Quaternion& operator*=(const Quaternion& other) {
            // quaternion multiplication
            Quaternion result = (*this)*other;

            // apply renormalization
            int32_t invnorm = this->invnorm();
            q[0] = Unit( Unit::to_i32(result.q[0].val*(int64_t)invnorm) );
            q[1] = Unit( Unit::to_i32(result.q[1].val*(int64_t)invnorm) );
            q[2] = Unit( Unit::to_i32(result.q[2].val*(int64_t)invnorm) );
            q[3] = Unit( Unit::to_i32(result.q[3].val*(int64_t)invnorm) );

            return *this;
        }

        /* returns the inverse of a Quaternion */
        Quaternion inv() {
            return Quaternion(q[0], -q[1], -q[2], -q[3]);
        }
        double norm() {
            return sqrt( this->dot() ) / Unit::ONE;
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
