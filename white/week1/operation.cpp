#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int x = 5;
    x = 6;
    cout << x <<endl;

    // Пример показывает что при присваивании в
    // с++ происходит полное глубое копирование
    // присваиваемое переменной
    string s = "Hello";
    string t = s;
    t += ", world";
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    vector<string> w = {"a", "b", "c"};
    vector<string> v;

    v = w;
    v[0] = "d";

    cout << w[0] << " "<< w[1] << endl;
    cout << v[0] << " "<< v[1] << endl;

    int a = 11, C;
    int b = 3;
    double b_d = 3;
    C = a / b;
    // деление на цело так как типы int
    cout << a / b << endl;
    // деление с запятой
    cout << a / b_d << endl;
    // first varian
    x = x + 5;
    // second variant
    x += 5;
    x -= 5;
    x *= 5;
    x /=5 ;
    cout << x<< endl;
    // Постфиксный инкремент возвращает то значение 
    // переменной, которое было до увеличения 
    // переменной
    double A = x++;
    cout << x << endl;
    cout << "A = " << A << " x = "  << x << endl;

    // Префексный инкремент возвращает то значение 
    // переменной, которое стало после увеличения 
    // переменной
    double B = ++x;
    cout << "B = " << B << " x = " << x << endl;

    // Аналогично есть операции декремента

    cout <<"A = "<< A << endl;
    cout <<"B = "<< B << endl;
    return 0;
}