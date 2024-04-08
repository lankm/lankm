#include <iostream>
#include <list>
#include <string>
#include <array>
#include <fstream>
#include <algorithm>

using namespace std;

#define Tdim 9
#define Ldim 7
#define Mdim 3
typedef array<array<array<list<string>,Mdim>,Ldim>,Tdim> Units;

void addUnit(Units& units, char time, char length, char mass, string name) {
    units[time+4][length+3][mass+1].push_back(name);
}
list<string> getUnit(Units& units, char time, char length, char mass) {
    return units[time+4][length+3][mass+1];
}
void defineUnits(Units& units) {
    addUnit(units, 0, 0, 0, "Unitless");
    addUnit(units, 1, 0, 0, "Time");
    addUnit(units, 0, 1, 0, "Length");
    addUnit(units, 0, 0, 1, "Mass");

    addUnit(units, -1, 1, 0, "Velocity");
    addUnit(units, -2, 1, 0, "Acceleration");
    addUnit(units, -3, 1, 0, "Jerk");
    addUnit(units, -4, 1, 0, "Snap");

    addUnit(units, -1, 1, 1, "Momentum");
    addUnit(units, -1, 1, 1, "Impulse");
    addUnit(units, -2, 1, 1, "Force");
    addUnit(units, -2, 2, 1, "Energy");
    addUnit(units, -3, 2, 1, "Power");
    addUnit(units, -2, -1, 1, "Pressure");

    addUnit(units, 0, 2, 1, "MomentOfInertia");
    addUnit(units, -2, 2, 1, "Torque");
    addUnit(units, 0, 0, 0, "Angle");
    addUnit(units, -1, 0, 0, "AngularVelocity");
    addUnit(units, -2, 0, 0, "AngularAcceleration");

    addUnit(units, 0, 2, 0, "Area");
    addUnit(units, 0, 2, 0, "Volume");

    addUnit(units, -1, 0, 0, "Frequency");
}

void createMacros(ofstream& fout) {
    string defineOperator = "#define DEFINE_OPERATOR(class1, op, class2, class3) \\\n"
                            "class3 class1::operator op(const class2& other) {return this->val + other.val;}\n";
    fout << defineOperator;

    string defineAssignmentOperator = "#define DEFINE_ASSIGNMENT_OPERATOR(class1, op, class2) \\\n"
                                      "class1& class1::operator op(const class2& other) {this->val += other.val; return *this;}\n";
    fout << defineAssignmentOperator;

    string addOperator = "#define ADD_OPERATOR(op, class2, class3) \\\n"
                         "class3 operator op(const class2& other);\n";
    fout << addOperator;

    string addAssignmentOperator = "#define ADD_ASSIGNMENT_OPERATOR(op, class2, class3) \\\n"
                                   "class3& operator op(const class2& other);\n";
    fout << addAssignmentOperator;
}
void forwardDeclareClasses(Units& units, ofstream& fout) {
    for(int i=0; i<Tdim*Ldim*Mdim; i++) {
        list<string> names = units[0][0][i];
        for(string unit : names) {
            fout << "class " << unit << ';' << endl;
        }
    }
}
void DeclareUnit(Units& units, ofstream& fout) {
    string unitClass = "class Unit {\n"
    "    public:\n"
    "    double val;\n"
    "    Unit() {this->val = 0;}\n"
    "    Unit(double val) {this->val = val;}\n"
    "    friend std::ostream& operator<<(std::ostream& os, const Unit& obj) {return os << obj.val;}\n"
    "};\n";
    fout << unitClass;
}
void forwardDeclareFunctions(Units& units, ofstream& fout) {
    for(int i=0; i<Tdim; i++) {
    for(int j=0; j<Ldim; j++) {
    for(int k=0; k<Mdim; k++) {
        list<string> names = units[i][j][k];
        // if(not names.empty()) {
        //     fout << "class " << 'T'<< 'T'<< 'T'<< 'T'<< 'T'<< 'T' << " : public Unit"
        // }
        // for(string unit : names) {
        //     fout << "class " << unit << ';' << endl;
        // }
    }}}
}
void DeclareFunctions(Units& units, ofstream& fout) {

}
void createClasses(Units& units, ofstream& fout) {
    forwardDeclareClasses(units, fout);
    DeclareUnit(units, fout);
    forwardDeclareFunctions(units, fout);
    DeclareFunctions(units, fout);
}
void createUnitHeader(Units& units, ofstream& fout) {
    string startHeaderGuard = "#ifndef UNIT_GUARD_H\n#define UNIT_GUARD_H\n";
    fout << startHeaderGuard;

    string includes = "#include <iostream>\n";
    fout << includes;

    createMacros(fout);

    createClasses(units, fout);

    string endHeaderguard = "#endif\n";
    fout << endHeaderguard;
}

class Unit {
    public:
        double val;

        Unit() {this->val = 0;}
        Unit(double val) {this->val = val;}

        friend std::ostream& operator<<(std::ostream& os, const Unit& obj) {return os << obj.val;}

};
class T0L0M0 : public Unit {
    public:
        T0L0M0() {this->val = 0;}
        T0L0M0(double val) {this->val = val;}
};
class Unitless: public T0L0M0 {
    public:
        Unitless() {this->val = 0;}
        Unitless(double val) {this->val = val;}
        Unitless(T0L0M0 unit) {this->val = unit.val;}
};

int main(int argc, char **argv) {
    ofstream fout("test.hpp");
    if(not fout.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }
    
    Units units;
    defineUnits(units);
    createUnitHeader(units, fout);

    fout.close();

    return 0;
}
