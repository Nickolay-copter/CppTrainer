#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*Функции единственный способ 
написания рекуосивных алгоритмов

Язвк С++ - язык со статической типизацией

у return есть особенность - функция завершает выполнение
программы*/
bool Contains(vector<string> words, string w){
    for(auto s: words){
        if (s == w){
            return true;
        }
    }
    return false;
}

int Sum (int x, int y){
    return x + y;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << Sum(x, y) << endl;
    cout << Contains({"air", "water", "fire"}, "fire");
    return 0;
}
