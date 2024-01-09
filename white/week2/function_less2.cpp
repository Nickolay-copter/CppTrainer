#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*Так как функция ничего не возвращает, значит
мы должны объявить пустой тип void*/
void PrintWord(vector<string> words){
    for (auto s: words){
        cout << s << " ";
    }
}

void ChangeInt(int x) {
    x = 42;
}

int main(){
    PrintWord({"Air", "Water", "Fair"});
    int a = 5;
    /*a недолжно зменить значение, та как в функцию передаются
    копии значений*/
    ChangeInt(a);
    return 0;
}