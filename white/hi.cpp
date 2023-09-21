// с++ язык со статической типизацией
//Библиотека используема для ввода вывода
#include <iostream>
// Библиотека поддержки строк
#include <string>
// Библиотека поодержки векторов
#include <vector>
// Библиотека для задания словарей
#include <map>
using namespace std;

struct Person{
    string name;
    string surname;
    int age;
};

int main() {

    // ВСТРОЕННЫЕ ТИПЫ //
    /////////////////////
    int x = -5;
    double pi = 3.14;
    bool logical_value = false;
    // для хранения символов
    char symbol = 'Z'; 
    // для хранения строк
    string hw = "Hi, world!";
    // тип вектор предназначен для хранения переменных одного типа
    vector<int>  nums = {1,3,5,7};

    // Более сложная структура данных чем вектор - словарь
    // Объявление словаря ставящий в соответствие строке - число
    map<string, int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;

    cout<< "two is "<< name_to_value["two"] <<"\n";
    // вывод длины вектора
    cout <<"Длина вектора "<< nums.size() << "\n";
    // cout - функция вывода. << - оператор вывода
    cout << "Hello, world"<<"\n";

    // ПОЛЬЗОВАТЕЛЬСКИЕ ТИПы //
    // позволяет создавать свои
    // пользовательские типы и внедрять в строенные в с++ типы
    vector<Person> staff, staff_2;
    // добавим два объекта в вектор staff. push_back - добавляет в конец вектора элемент
    staff.push_back({"Ivan", "Ovanov", 25});
    staff.push_back({"Petr", "Petrov", 25});

    cout<< "Первый сотрудник " << staff[0].name<<" " << staff[0].surname;
    return 0;
}