#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int A, a;
    vector<int> v;
    cin >> A;
    if (A > 0) {
        do 
        {
            v.push_back(A % 2);
            A /= 2; 
        }while (A != 0);
        int N = v.size();
        for (int n = N - 1; n >= 0; --n)
            cout << v[n];
    }
    return 0;
}