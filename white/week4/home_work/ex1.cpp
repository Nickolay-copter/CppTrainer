#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Specialization{
    string value;
    explicit Specialization(string new_value){
        value = new_value;
    }
};

struct Course{
    string value;
    explicit Course(string new_value){
        value = new_value;
    }
};

struct Week{
    string value;
    explicit Week(string new_value){
        value = new_value;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization spec, Course cs, Week wk){
        specialization = spec.value;
        course = cs.value;
        week = wk.value; 
    }
};
