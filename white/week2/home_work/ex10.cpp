#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

int main(){
    int num_operation, day;
    int num_month = 0;
    int next_month;
    int current_month;
    string task;
    string command;
    vector<int> days_in_month = {31, 28, 31,30,31,30,31,31,30,31,30,31};
    vector<string> tmp;
    vector<vector<string>> organize(days_in_month[num_month]);
    vector<vector<string>> dump_cache;
    cin >> num_operation;
    for (int i = 0; i < num_operation; i++){
        cin >> command;
        if (command == "DUMP"){
            cin >> day;
            dump_cache.push_back(organize[day - 1]);
        } else{
            if (command == "ADD"){
                cin >> day >> task;
                organize[day-1].push_back(task); 
            } else if (command == "NEXT"){
                ++num_month;
                next_month = days_in_month[(num_month)%12];
                current_month = organize.size();
                if (current_month > next_month){
                    for (int j = next_month; j < current_month; j++){
                        for (string s : organize[j]){
                            organize[next_month - 1].push_back(s);
                        }
                    }
                    organize.resize(next_month);
                } else {
                    organize.resize(next_month);
                }
                
            }
        }
    }
    for (vector<string> v: dump_cache){
        cout << v.size() << " ";
        for (string t : v){
            cout << t << " ";  
        }
        cout << endl;
    }
    
    return 0;
}