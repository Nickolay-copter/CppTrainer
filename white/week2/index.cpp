#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*Функция Swap не должена поменять местами переменные, потому что 
параметры были скопированы в функцию Swap*/
void Swap(int x, int y){
    int tmp = x;
    x = y;
    y = tmp;
}
/*Чтобы функция Swap изменяла местами переменные, параметры должны 
передаваться как ссылка Swap. Переменные должны быть не int, а ссылка на int*/
void Swap1(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}
/*Не решает проблему дублирования кода*/
vector<int> Sort(vector<int> v){
    sort(begin(v), end(v));
    return v;
}
/*Решает проблему дублирования кода*/
void Sort1(vector<int>& v){
    sort(begin(v), end(v));
}
/*Главной задачей ссылок является изменение
переменной из под отдельной функции*/
int main(){
    vector<int> nums = {3,6,1,2,0,2};
    vector<int> nums1 = {3,6,1,2,0,2};
    vector<int> nums2 = {3,6,1,2,0,2};
    sort(begin(nums), end(nums));
    nums1 = Sort(nums1);
    Sort1(nums2);
    for(auto n : nums)
        cout << n << " ";
    cout << endl;
    for(auto n : nums1)
        cout << n << " ";
    cout << endl;
    for(auto n : nums2)
        cout << n << " ";
    cout << endl;
    int a = 1, a1 = 3;
    int b = 2, b1 = 4;
    Swap(a,b);
    cout <<"a == "<< a << '\n';
    cout <<"b == "<< b << '\n';
    Swap1(a1, b1);
    cout <<"a1 == "<< a1 << '\n';
    cout <<"b1 == "<< b1 << '\n';    
    return 0;
}

/* Использование ссылок хорошо для модификации 
фактических пареметров функции */