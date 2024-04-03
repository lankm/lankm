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

        Unit() {this->val = 0;}
        Unit(double val) {this->val = val;}
};

/* s:0, m:0, kg:0, A:0, K:0, cd:0 */
class Unitless : public Unit {
    public:
        Unitless() : Unit() {}
        Unitless(double val) : Unit(val) {}

        /* addition */
        Unitless operator+(const Unitless& other);
        Unitless& operator+=(const Unitless& other);
        /* subtraction */
        Unitless operator-(const Unitless& other);
        Unitless& operator-=(const Unitless& other);
        /* multiplication */
        Unitless operator*(const Unitless& other);
        Unitless& operator*=(const Unitless& other);
        Time operator*(const Time& other);
        /* division */
        Unitless operator/(const Unitless& other);
        Unitless& operator/=(const Unitless& other);

        friend std::ostream& operator<<(std::ostream& os, const Unitless& obj) {return os << obj.val;}
};
/* s:1, m:0, kg:0, A:0, K:0, cd:0 */
class Time : public Unit {
    public:
        Time() : Unit() {}
        Time(double val) : Unit(val) {}

        /* addition */
        Time operator+(const Time& other);
        Time& operator+=(const Time& other);
        /* subtraction */
        Time operator-(const Time& other);
        Time& operator-=(const Time& other);
        /* multiplication */
        Time operator*(const Unitless& other);
        Time& operator*=(const Unitless& other);
        /* division */
        Time operator/(const Unitless& other);
        Time& operator/=(const Unitless& other);

        friend std::ostream& operator<<(std::ostream& os, const Time& obj) {return os << obj.val;}
};

Unitless Unitless::operator+(const Unitless& other) {return this->val + other.val;}
Unitless& Unitless::operator+=(const Unitless& other) {this->val += other.val; return *this;}
Unitless Unitless::operator-(const Unitless& other) {return this->val - other.val;}
Unitless& Unitless::operator-=(const Unitless& other) {this->val -= other.val; return *this;}
Unitless Unitless::operator*(const Unitless& other) {return this->val * other.val;}
Unitless& Unitless::operator*=(const Unitless& other) {this->val *= other.val; return *this;}
Time Unitless::operator*(const Time& other) {return this->val * other.val;}
Unitless Unitless::operator/(const Unitless& other) {return this->val / other.val;}
Unitless& Unitless::operator/=(const Unitless& other) {this->val /= other.val; return *this;}

Time Time::operator+(const Time& other) {return this->val + other.val;}
Time& Time::operator+=(const Time& other) {this->val += other.val; return *this;}
Time Time::operator-(const Time& other) {return this->val - other.val;}
Time& Time::operator-=(const Time& other) {this->val -= other.val; return *this;}
Time Time::operator*(const Unitless& other) {return this->val * other.val;}
Time& Time::operator*=(const Unitless& other) {this->val *= other.val; return *this;}
Time Time::operator/(const Unitless& other) {return this->val / other.val;}
Time& Time::operator/=(const Unitless& other) {this->val /= other.val; return *this;}
#endif
