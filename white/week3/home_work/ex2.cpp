#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void Print(const vector<string>& v){
    for (const string item: v){
        cout << item<< " ";
    }
}
int main(){
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& item : v){
        cin >> item;
    }
    sort(begin(v), end(v), [](string x, string y){
        for (auto& item: x){
            item = tolower(item);
        }
        for (auto& item: y){
            item = tolower(item);
        }
        return x < y;});
    Print(v);
    return 0;
}