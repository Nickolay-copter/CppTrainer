#include<iostream>
#include<string>
using namespace std;
 
bool IsPalindrom(string words){
    string out;
    for(int i = words.size() - 1; i >= 0; i--){
        out.push_back(words[i]);
    }
    if (out == words)
        return true;
    else
        return false;
}

int main(){
    string word;
    cin >> word;
    cout << IsPalindrom(word);
    return 0;
}