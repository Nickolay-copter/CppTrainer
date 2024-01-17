#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string name;
    string& name_s = name;
    string& text = ("Hi, "+ name);
    cin >> name;
    cout << text;
    return 0;
}