#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = 4, y = 5;
    cout<< (x + y)/2;
    cout<< "\n";
    if (x == y){
        cout<< "equal";
        } 
    else{
        cout<< "not equal";
    }
    cout<< "\n";
    string xs = "abc", ys = "def";
    if (x != y){
        cout<< "not equal";
        } 
    else{
        cout<< "equal";
    }
    cout<< "\n";
    // сравнение строе производится лексикографическим способом
    if (x > y){
        cout<< "y less x";
        } 
    else if (x == y) {
        cout<< "y equal x";
    }
    else{
        cout<< "x less y";
    }
    return 0;
}