#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    double A, B, C;
    double x1, x2;
    double D;

    cin >> A >> B >> C;
    D = B*B - 4 * A * C;
    if (A != 0) {
        if (D > 0) {
            x1 = (-B + sqrt(D)) / (2 * A);
            x2 = (-B - sqrt(D)) / (2 * A);
            cout << x1 << " "<< x2;
        } else if (D == 0) {
            x1 = -B / (2 * A);
            cout << x1;
        } else {
            cout << "";
        }
    } else {
        if (B != 0) {
            x1 = -C/B;
            cout << x1;
        } else {
            cout << "";
        } 
    }
    return 0;
}