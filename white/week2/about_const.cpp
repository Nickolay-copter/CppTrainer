#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* const модификтор типа запрещающий
изменение переменных
Главная функция const помощь программисту по предотвращению
модификации случайных переменных*/
int main(){

    /* Ошибка!*
    const int x = 5
    x += 1;
    */
    string s = "hello";
    cout << s.size() << endl;
    s += ", world";
    string t = s + "!";
    cout << s;
    /* Ошибка!
    const string s = "hello";
    cout << s.size() << endl;
    s += ", world";
    string t = s + "!";
    cout << s;    
    */
    
    /* Ошибка модификатор const распространяется и на элементы контейнера
    const vector<string> w = {"hello"};
    w[0][0] = 'H';
    w.push_back("");
    cout << w[0];
    */
    return 0;
}