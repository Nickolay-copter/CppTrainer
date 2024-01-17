#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int Q, num_stop;
    int track_count = 0;
    string stop, resol;
    set<string> stop_dict;
    vector<string> command_history;
    map<set<string>, int> stop_map;
    cin >> Q;
    for (int q = 0; q < Q; q++){
        cin >> num_stop;
        stop_dict.clear();
        for (int i = 0; i < num_stop; i++){
            cin >> stop;
            stop_dict.insert(stop);
        }

        if (stop_map.count(stop_dict) == 1){
            resol = "Already exists for " + to_string(stop_map[stop_dict]);           
        } else {
            ++track_count;
            stop_map[stop_dict] = track_count;
            resol = "New bus "+ to_string(track_count);
        }
        command_history.push_back(resol);
    }
    for (const string& res : command_history)
        cout << res << endl;
    return 0;
}