#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int No, n = 1;
    int k, i, wc = 0;
    vector<bool> live_order;
    vector<int> worry_count;
    string op_name;
    cin >> No;
    while (n <= No){
        cin >> op_name;
        if (op_name == "WORRY"){
            cin >> i;
            live_order[i] = true;
        } else if (op_name == "QUIET"){
            cin >> i;
            live_order[i] = false;
        } else if (op_name == "COME"){
            cin >> k;
            if (k >= 0 ){
                live_order.insert(live_order.end(), k, false);
            } else {
                live_order.erase(live_order.end() + k, live_order.end());
            }
        } else if (op_name == "WORRY_COUNT"){
            for (bool i : live_order){
                if (i == true){
                    wc++;
                }
            }
            worry_count.push_back(wc);
            wc = 0;
        } else {
            cout << "Такой команды нет"<< endl;
        }
        ++n;
    }
    for (int i : worry_count)
        cout << i << endl;
    
    return 0;
}