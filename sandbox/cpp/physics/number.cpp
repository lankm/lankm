#include <cstdint>
#include <iostream>
#include <cmath>
#include <iomanip>

#define BIT_ALIGN 30
class Unit {
    /* Represents a number between -2.0 and 1.9999...
     * Implemented to be fast and simple.
     * More precise than a float32_t.
     */
    private:
        int32_t val;
        
        Unit(int32_t num) {
            val = num;
        }
    public:
        Unit() {
            val = ((uint32_t)1 << BIT_ALIGN);
        }
        Unit(double num) {
            val = num*Unit().val;
        }

        // addition ===========================================================
        Unit operator+(const Unit& other) const {
            return Unit(val + other.val);
        }
        // subtraction ========================================================
        Unit operator-(const Unit& other) const {
            return Unit(val - other.val);
        }
        // multiplication =====================================================
        Unit operator*(const Unit& other) const {
            // multiply then shift right
            int64_t calc = ( (int64_t)val * (int64_t)other.val) >> BIT_ALIGN;
            return Unit( (int32_t)calc );
        }
        // division ===========================================================
        Unit operator/(const Unit& other) const {
            // shift left then divide
            int64_t calc = ( ((int64_t)val<<BIT_ALIGN) / (int64_t)other.val );
            return Unit( (int32_t)calc );
        }

        friend std::ostream& operator<<(std::ostream& os, const Unit& obj) {
            os << (double)obj.val / (double)Unit().val;
            return os;
        }
};

# define PI2 (uint64_t)1<<32
class Angle {
    /* Represents an angle between 0-1.9999...pi radians.
     * Utilizes over/underflows to represent rotations.
     * More precise than float32_t.
     * Keeps precision after multiple rotations.
     */
    private:
        uint32_t ang;
    public:
        Angle() {
            ang = 0;
        }
        Angle(double theta) {
            double rem = fmod(theta, 2*3.1415926535897932384626);
            rem /= 2*3.1415926535897932384626;
            rem *= PI2;

            ang = (uint32_t)rem;
        }

        friend std::ostream& operator<<(std::ostream& os, const Angle& obj) {
            os << obj.ang;
            return os;
        }

};

class Quaternion {
    private:
        Unit q[4];
    public:

};
