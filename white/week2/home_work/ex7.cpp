#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& v){
    vector<int> rcopy_v = v;
    int N, tmp;
    N = v.size() / 2;
    for (int si = 0, fi = v.size() - 1; si < N; si++, fi--){
        tmp = rcopy_v[si];
        rcopy_v[si] = rcopy_v[fi];
        rcopy_v[fi] = tmp;
    }
    return rcopy_v;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> source = {a, b, c, d}, rsource;

    rsource = Reversed(source);
    for (auto i : rsource)
        cout << i << "";
    return 0;
}