#include<iostream>
#include<vector>
#include<string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    for (auto element : source)
        destination.push_back(element);
    source.clear();
}

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<string> source = {a, b};
    vector<string> destination = {c, d};
    MoveStrings(source, destination);
    for (auto i : source)
        cout << i << "";
    cout << endl;   
    for (auto i : destination)
        cout << i << "";
    return 0;
}