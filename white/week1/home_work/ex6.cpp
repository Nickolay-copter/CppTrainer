#include <iostream>

using namespace std;

int main() {
    int A, B;
    int Price;
    cin >> A >> B;
    bool F = (A >= 1) && (B <= 30000);
    if ((A <= B) && F) {
        for(Price = A + A % 2; Price <= B; Price += 2) {
            cout << Price <<" ";
        }
        return 0;
    }
    return 0;
}