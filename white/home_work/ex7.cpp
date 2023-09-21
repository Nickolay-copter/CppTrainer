#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string word;
    int count = 0, flag = -2;
    cin >> word;
    int N = word.size();
    for(int i = 0; i <= N; i++){
        if (word[i] == 'f'){
            count++;
            flag = -1;
        }
        if (count == 2){
            flag = i;
            break;
        }
    }
    cout << flag;
    return 0;
}