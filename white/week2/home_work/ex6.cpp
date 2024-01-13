#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v){
    reverse(v.begin(), v.end());
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> source = {a, b, c, d};
    Reverse(source);
    for (auto i : source)
        cout << i << "";
    return 0;
}