#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int a = 2;
    int b = 5;
    if (a < b){
        cout << "a less then b"<< endl;
    }
    string as = "fire";
    string bs = "water";
    /* Сравнение строк проводится лексикографически
    bs > as потому что буква f идёт раньше чем w
    */
    if (as < bs){
        cout << "STRING a less then b"<< endl;
    }

    if (as == bs){
        cout << "STRING: as equal then b"<< endl;
    } else {
        cout << "STRING: as isn't equal then b"<< endl; 
    }
    vector<string> avs = {"fire", "water"};
    vector<string> bvs = {"fog", "air"};

    if (avs == bvs){
        cout << "STRING: avs equal then b"<< endl;
    } else {
        cout << "STRING: avs isn't equal then b"<< endl; 
    }

    map<string, int> am;
    am["one"] = 1;
    // b - пустой словарь
    map<string, int> bm;
    
    if (am == bm){
        cout << "MAP: am equal then bm"<< endl;
    } else {
        cout << "MAP: am isn't equal then bm"<< endl; 
    }
    string s = "abs";
    if (!s.empty() && s < "zzz") {
        cout << s<< endl;
    }
    return 0;
}