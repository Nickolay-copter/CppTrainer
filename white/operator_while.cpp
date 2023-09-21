#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    int sum_map = 0;
    string concat;
    /* запись контейнеров */
    vector<int> a = {1,2,4,5};
    map<string, int> b = {{"c", 1}, {"b", 2}, {"a", 3}};
    /* Запись цикла Range-based-for. Используется
    обычно для выполнения каких то операций
     не связанных с индексами на прямую*/
    for (auto m : b){
        concat += m.first;
        sum_map += m.second;
    }
    cout << concat <<endl;
    cout << sum_map <<endl;
    for(auto s : a){
        sum += s;
    }
    cout << sum<< endl;
    
    string S = "sfefsefni789mkn";
    int idx = 0;
    for (auto is : S){
        if (is == 's'){
            cout << idx <<" ";
        }
        idx++;
    }
    cout << endl;
    /* Запись обычного цикла. Обычно используется для 
    определения индекса*/
    for (int m = 0; m < S.size(); m++){
        if (S[m] == 's')
            cout << m <<" ";
    }
    /* Допустим мы хотим выйти из цикла на первом попавшемся 
    совпадении. Оператор break выходит за последнюю закрывающуюся
    фигурную скобку тела цикла*/
    cout << endl;
    for (int m = 0; m < S.size(); m++){
        if (S[m] == 's') {
            cout << m <<" ";
            break;
        }
    }
    cout<< "Yes";

    return 0;
}