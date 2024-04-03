#ifndef UNIT_GUARD_H
#define UNIT_GUARD_H

#include <cstdint>
#include <iostream>
#include <cmath>
#include <iomanip>

class Unit;
class Unitless;
class Mass;
class Time;
class Length;
class Electric_Current;
class Temperature;
class Luminous_Intensity;
class Area;
class Volume;
class Frequency;
class Force;
class Pressure;
class Energy;
class Power;
class Electric_Charge;

class Unit {
    public:
        double val;

        Unit() {
            this->val = 0.0;
        }
        Unit(double val) {
            this->val = val;
        }
};
/* s:0, m:0, kg:0, A:0, K:0, cd:0 */
class Unitless : Unit {
    public:
        Unitless() : Unit() {}
        Unitless(double val) : Unit(val) {}

        /* addition */
        Unitless operator+(const Unitless& other) const {
            return Unitless(val + other.val);
        }
        /* subtraction */
        Unitless operator-(const Unitless& other) const {
            return Unitless(val - other.val);
        }

        /* multiplication */
        Time operator*(const Time& other) const {
            return Time(val * other.val);
        }
        /* division */
        Unit operator/(const Unit& other) const {
            // shift left then divide
            return Unit();
        }
};
/* s:0, m:0, kg:1, A:0, K:0, cd:0 */
class Mass : Unit {

};
/* s:1, m:0, kg:0, A:0, K:0, cd:0 */
class Time : public Unit {
    public:
        Time() : Unit() {}
        Time(double val) : Unit(val) {}
};
/* s:0, m:1, kg:0, A:0, K:0, cd:0 */
class Length : Unit {

};
/* s:0, m:0, kg:0, A:1, K:0, cd:0 */
class Electric_Current : Unit {

};
/* s:0, m:0, kg:0, A:0, K:1, cd:0 */
class Temperature : Unit {

};
/* s:0, m:0, kg:0, A:0, K:0, cd:1 */
class Luminous_Intensity : Unit {

};
/* s:0, m:2, kg:0, A:0, K:0, cd:0 */
class Area : Unit {

};
/* s:0, m:3, kg:0, A:0, K:0, cd:0 */
class Volume : Unit {

};
/* s:-1, m:0, kg:0, A:0, K:0, cd:0 */
class Frequency : Unit {

};
/* s:-2, m:1, kg:1, A:0, K:0, cd:0 */
class Force : Unit {

};
/* s:-2, m:-1, kg:1, A:0, K:0, cd:0 */
class Pressure : Unit {

};
/* s:-2, m:2, kg:1, A:0, K:0, cd:0 */
class Energy : Unit {

};
/* s:-3, m:2, kg:1, A:0, K:0, cd:0 */
class Power : Unit {

};
/* s:-3, m:2, kg:1, A:0, K:0, cd:0 */
class Electric_Charge : Unit {

};

#endif
