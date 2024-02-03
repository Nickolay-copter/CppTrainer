#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Incognizable {
    int f1 = 10;
    int f2 = 2;   
};

void PrintIncognizable(const Incognizable& v){
    cout << "f1 = "<< v.f1 << " " << "f2 = " << v.f2 << endl;
} 

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    PrintIncognizable(a);
    PrintIncognizable(b);
    PrintIncognizable(c);
    PrintIncognizable(d);
    return 0;
}