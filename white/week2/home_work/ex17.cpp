#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int N;
    string command, word1, word2;
    map<string, set<string>> equal_words;
    set<set<string>> call_history;    
    vector<string> command_history;
    cin >> N;
    for (int n = 0; n < N; n++){
        cin >> command;
        if (command == "ADD"){
            cin >> word1 >> word2;
            equal_words[word1].insert(word2);
            equal_words[word2].insert(word1);
            call_history.insert({word1, word2});
        } else if (command == "COUNT"){
            cin >> word1;
            command_history.push_back(to_string(equal_words[word1].size()));
        } else if (command == "CHECK"){
            cin >> word1 >> word2;
            if (call_history.count({word1, word2}) == 1){
                command_history.push_back("YES"); 
            } else {
                command_history.push_back("NO");
            }
        } else {
            cout << "Такой команды нет";
        }
    }
    for (const string& c : command_history)
        cout << c << endl;
    return 0;
}