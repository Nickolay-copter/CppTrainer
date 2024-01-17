#include <map>
#include<iostream>
#include<string>
using namespace std;

int main(){
    map<string, int> m = {{"ones", 1}, {"two", 2}};
    /*
    В версии до 17 мы бы для вывода словаря писали
    цикл
    */
    for (const auto& item : m){
        cout << item.first << ": " << item.second << endl;
    }
    // В новом стандарте:
    for (const auto& [key, value] : m){
        cout << key << ": " << value << endl;
    }
    return 0;
}