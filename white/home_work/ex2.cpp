#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int i = 0;
    string tmp, minv = "";
    while (i < 3) {
        cin >> tmp;
        if (i == 0) {
            minv = tmp;
        } else if (tmp < minv) {
            minv = tmp;
        }
        i++;
    }
    cout << minv;
    return 0;
}

    
