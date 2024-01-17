#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void WarmDays(const vector<int>& v, vector<int>& warm_days){
    int A = 0, s = 0, N;
    N = v.size();
    for (int i : v){
        s += i;
    }
    A = s / v.size();
    for (int i = 0; i < N; i++){
        if (v[i] > A){
            warm_days.push_back(i);
        }
    }
    cout << warm_days.size() << endl;
    for (int d : warm_days)
        cout << d << " ";
}

int main()
{
    int Nd;
    cin >> Nd;
    vector<int> temp(Nd);
    vector<int> warm_days;
    for (int& t : temp)
        cin >> t;
    WarmDays(temp, warm_days);
    return 0;
}