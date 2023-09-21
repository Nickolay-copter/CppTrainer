#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int x = 4;
    string y = "Hello";
    cout<< x<< ' '<< y << '\n';

    /* компилятор скажет что он не знает оператора вывода вектора, т.к.
    нет единого способа преобразования вектора в поток - с пробеламти/без, с запятыми/без
    vector<int> d = {1,2};
    cout<< d;
    */
    // Ввод в консоли consol input
    int a, b;
    cout<< "Введите первое слагаемое: ";
    cin >> a;
    cout<< "Введите второе слагаемое: ";
    cin >> b;
    cout<< a+b << endl; 

    // Строки по умолчанию считываются 
    // до первого пробельного символа
    string name, surname;
    cin >> name;
    cout<< "Hello " << name << endl;
    
    // Пример с вводом через пробел
    cin >> name >> surname;
    cout << "Hello, " << name << " "<< surname;

    return 0;
}