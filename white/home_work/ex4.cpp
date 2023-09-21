#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    bool bl, al;
    cin >> a >> b;
    bl = (b > 0) & (b <= 1e6);
    al = (a > 0) & (a <= 1e6);
    if (b == 0) {
        cout << "Impossible";
    } else if (bl || al) {
        c = a / b;
        cout << c;
    } else {
        return 0;
    }
    return 0;
}