#include <algorithm> // библиотека позволяющая подсчитать количество элементов в контейнере
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    // пример объявления простого контейнера в виде строки
    string s = "abcdefg";
    // переберём все занчения
    for(char c : s){
        cout<< c <<", ";
    }
    cout<< endl;
    vector<int> nums = {1, 3, 4, 5, 6};
    int quintity = 0;
    for(int c : nums){
        cout<< c <<", ";
        if (c == 5){
           quintity++; 
        }
    }
    cout<< endl;
    cout<< "В векторе nums "<< quintity<<" пятёрок"<< endl;
    // добавление элементов в вектор
    nums.push_back(nums[1]);
    for(int c : nums){
        cout<< c <<", ";
    }
    cout<< endl;
    // количество элементов можно подсчитать короче
    int short_quantity = count(begin(nums), end(nums), 5);
    // begin и end - специальный способ задать последовательность в библиотеке алгоритмов
    // сортировка
    sort(begin(nums), end(nums));
    cout<< "сортированный вектор nums ";
    for(int c : nums){
        cout<< c <<", ";
    }
    cout<< endl;
    // сортировку также можно проводить и над строками
    vector<string> st_var = {"hi", "Milk", "Built", "H"};
    sort(begin(st_var), end(st_var));
    cout<< "сортированный вектор st_var ";
    for(string c : st_var){
        cout<< c <<", ";
    }
    cout<<endl;
    // также можно и for(auto c : nums){}
    vector<char> char_nums = {'1', '3', '4', '5', '6'};
    for(auto c : char_nums){
        cout<< c <<", ";
    }
    return 0; 
    
} 