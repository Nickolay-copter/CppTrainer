#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void BuildCharCounters(map<char, int>& m, const string& word){
    for (const char& character : word){
        ++m[character];
    }
}

int main(){
    int Num;
    string word1, word2;
    map<char, int> map1, map2;
    map<bool, string> decide = {{true, "YES"}, {false, "NO"}};
    vector<string> check;
    cin >> Num;
    for (int i = 0; i < Num; ++i){
        cin >> word1 >> word2;
        BuildCharCounters(map1, word1);
        BuildCharCounters(map2, word2);
        check.push_back(decide[(map1 == map2)]);
        map1.clear();
        map2.clear();
    }
    for (const string& w : check)
        cout << w << endl;
    return 0;
}