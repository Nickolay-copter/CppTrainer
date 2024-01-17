#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int N;
    string st;
    set<string> dict;
    cin >> N;
    for (int n = 0; n < N; n++){
        cin >> st;
        dict.insert(st);        
    }
    cout << dict.size();
    return 0;
}