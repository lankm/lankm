#ifndef UNIT_GUARD_H
#define UNIT_GUARD_H
#include <iostream>
#define DEFINE_OPERATOR(class1, op, class2, class3) \
class3 class1::operator op(const class2& other) {return this->val + other.val;}
#define DEFINE_ASSIGNMENT_OPERATOR(class1, op, class2) \
class1& class1::operator op(const class2& other) {this->val += other.val; return *this;}
#define ADD_OPERATOR(op, class2, class3) \
class3 operator op(const class2& other);
#define ADD_ASSIGNMENT_OPERATOR(op, class2, class3) \
class3& operator op(const class2& other);
class Snap;
class Jerk;
class Power;
class Pressure;
class AngularAcceleration;
class Acceleration;
class Force;
class Energy;
class Torque;
class AngularVelocity;
class Frequency;
class Velocity;
class Momentum;
class Impulse;
class Unitless;
class Angle;
class Mass;
class Length;
class Area;
class Volume;
class MomentOfInertia;
class Time;
class Unit {
public:
    double val;
    Unit() {this->val = 0;}
    Unit(double val) {this->val = val;}
friend std::ostream& operator<<(std::ostream& os, const Unit& obj) {return os << obj.val;}
};
#endif
