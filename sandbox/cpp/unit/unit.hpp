#ifndef UNIT_GUARD_H
#define UNIT_GUARD_H

#include <iostream>

#define DEFINE_OPERATOR(class1, op, class2, class3) \
class3 class1::operator op(const class2& other) {return this->val + other.val;}

#define DEFINE_ASSIGNMENT_OPERATOR(class1, op, class2) \
class1& class1::operator op(const class2& other) {this->val += other.val; return *this;}

#define DEFINE_STANDARD_OPERATORS(class1) \
DEFINE_ASSIGNMENT_OPERATOR(class1, +=, class1) \
DEFINE_ASSIGNMENT_OPERATOR(class1, -=, class1) \
DEFINE_ASSIGNMENT_OPERATOR(class1, *=, Unitless) \
DEFINE_ASSIGNMENT_OPERATOR(class1, /=, Unitless) \
DEFINE_OPERATOR(class1, +, class1, class1) \
DEFINE_OPERATOR(class1, -, class1, class1) \
DEFINE_OPERATOR(class1, *, Unitless, class1) \
DEFINE_OPERATOR(class1, /, Unitless, class1)

#define ADD_OPERATOR(op, class2, class3) \
class3 operator op(const class2& other);

#define ADD_ASSIGNMENT_OPERATOR(op, class2, class3) \
class3& operator op(const class2& other);

#define ADD_STANDARD_OPERATORS(class1) \
class1() : Unit() {} \
class1(double val) : Unit(val) {} \
ADD_ASSIGNMENT_OPERATOR(+=, class1, class1) \
ADD_ASSIGNMENT_OPERATOR(-=, class1, class1) \
ADD_ASSIGNMENT_OPERATOR(*=, Unitless, class1) \
ADD_ASSIGNMENT_OPERATOR(/=, Unitless, class1) \
ADD_OPERATOR(+, class1, class1) \
ADD_OPERATOR(-, class1, class1) \
ADD_OPERATOR(*, Unitless, class1) \
ADD_OPERATOR(/, Unitless, class1) \
friend std::ostream& operator<<(std::ostream& os, const class1& obj) {return os << obj.val;}

class Unit;
class Unitless;
class Time;
class Frequency;

class Unit {
    public:
        double val;

        Unit() {this->val = 0;}
        Unit(double val) {this->val = val;}
};

/* s:0, m:0, kg:0, A:0, K:0, cd:0 */
class Unitless : public Unit {
    public:
        ADD_STANDARD_OPERATORS(Unitless)

        ADD_OPERATOR(*, Time, Time)
        ADD_OPERATOR(*, Frequency, Frequency)
};

/* s:1, m:0, kg:0, A:0, K:0, cd:0 */
class Time : public Unit {
    public:
        ADD_STANDARD_OPERATORS(Time)
        ADD_OPERATOR(/, Time, Unitless)

        ADD_OPERATOR(*, Frequency, Unitless)

};
/* s:-1, m:0, kg:0, A:0, K:0, cd:0 */
class Frequency : public Unit {
    public:
        ADD_STANDARD_OPERATORS(Frequency)
        ADD_OPERATOR(/, Frequency, Unitless)

        ADD_OPERATOR(*, Time, Unitless)
};

DEFINE_STANDARD_OPERATORS(Unitless)
DEFINE_OPERATOR(Unitless, *, Time, Time)
DEFINE_OPERATOR(Unitless, *, Frequency, Frequency)

DEFINE_STANDARD_OPERATORS(Time)
DEFINE_OPERATOR(Time, /, Time, Unitless)
DEFINE_OPERATOR(Time, *, Frequency, Unitless)

DEFINE_STANDARD_OPERATORS(Frequency)
DEFINE_OPERATOR(Frequency, /, Frequency, Unitless)
DEFINE_OPERATOR(Frequency, *, Time, Unitless)

#endif
