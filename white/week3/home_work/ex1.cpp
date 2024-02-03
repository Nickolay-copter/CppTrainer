#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void Print(const vector<int>& v){
    for (const int item: v){
        cout << item<< " ";
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& item : v){
        cin >> item;
    }
    sort(begin(v), end(v), [](int x, int y){return abs(x) < abs(y);});
    Print(v);
    return 0;
}