#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int x = 4;
    int y = 6;
    vector<int> nums = {1,2,3}; 
    if (x == y) {
        cout << "equal";
    } else {
        cout << "not equal"<< endl;
    }
    // first varian for
    for (auto n : nums) {
        cout<< n<< " ";
    }
    cout<< endl;
    // second varian for
    /*
    
    Многострочный комментарий

    */
    int sum = 0, n = 5, i = 0;
    for (i = 0; i <= n; ++i){
        sum += i;
    }
    cout<< "for: "<< sum<< endl;
    sum = 0;
    i = 0;
    // while
    while (i <= n){
        sum += i;
        i++;
    }
    cout<< "while: "<< sum;
    return 0;
}