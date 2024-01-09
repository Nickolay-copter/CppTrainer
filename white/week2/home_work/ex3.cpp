#include<iostream>
#include<vector>
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
vector<string> PalindromFilter(vector<string> words_vector, int minLength){
    vector<string> out_vector = {};
    for(auto w: words_vector) {
        if (IsPalindrom(w) == true){
            if (w.size() >= minLength) {
                out_vector.push_back(w);
            }
        }
    }
    return out_vector;
}
int main(){
    string a, b, c;
    int Num;
    cin >> a >> b >> c;
    cin >> Num;
    vector<string> words_vector = {a,b,c}, pal_out;
    pal_out = PalindromFilter(words_vector, Num);
    for (auto w: pal_out){
        cout << w;
    }
    return 0;
}