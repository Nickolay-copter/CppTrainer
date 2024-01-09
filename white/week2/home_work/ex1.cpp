#include<iostream>
using namespace std;

int Factorial(int F){
    int out = 1;
    if (F > 0) {
        for (int i = 1; i <= F; ++i){
            out = out*i;
        }
        return out;
    } else {
        return 1;
    }
}

int main() {
    int F;
    cin >> F;
    cout << Factorial(F);
    return 0;
}