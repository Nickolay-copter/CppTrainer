#include <iostream>

using namespace std;

int main() {
    double N, A, B, X, Y;
    double Price;
    cin >> N >> A >> B >> X >> Y;
    if (A < B) {
        if (N > B) {
            Price = N * (1 - (Y / 100));
        } else if (N > A) {
            Price = N * (1 - (X / 100));
        } else {
            Price = N;
        }
        cout << Price;
        return 0;
    }
    return 0;
}