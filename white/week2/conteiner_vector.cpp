#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector_string(const vector<string>& v){
    for (string s : v)
        cout << s << " ";
}

void PrintVector_int(const vector<int>& v){
    for (int s : v)
        cout << s << " ";
}

void PrintVector_bool(const vector<bool>& v){
    for (bool s : v)
        cout << s << " ";
}

int main() {
    int n;
    // Задаём размер вектора
    cin >> n;
    // Определяем вектор длиной n через конструктор
    vector<string> v(n);
    // Для "заполнения вектора" обращемся к каждому элементу по ссылке
    for (string& s : v)
        cin >> s;
    // Также можно заранее не предопределять размер вектора
    vector<string> v2;
    string s;
    int i = 0;
    while (i < n){
        cin >> s;
        v2.push_back(s);
        cout << "Current size " << v2.size() << endl; 
        ++i;
    }
    PrintVector_string(v);
    cout << endl;
    PrintVector_string(v2);

    vector<int> days_in_month = {31, 28, 31, 30, 31};
    if (true){ // if year is leap 
        days_in_month[1]++;
    }
    cout << endl;
    PrintVector_int(days_in_month);
    // В векторе можно хранить элементы к привязке к их ключам
    vector<bool> is_holiday(28, false); // второй аргумент значение по умолчанию
    is_holiday[22] = true;
    // пока не удолась написать универасльную функцию по распечатыванию, в дальнейшем будет уточнение
    cout << endl;
    PrintVector_bool(is_holiday);

    // необходимо расширить вектор для переиспользования
    // оставит предыдущую информацию нетронутой
    is_holiday.resize(31);
    cout << endl;
    PrintVector_bool(is_holiday);

    // новый массив
    is_holiday.assign(31, false);
    cout << endl;
    PrintVector_bool(is_holiday);

    cout << endl << is_holiday.back();
    /*
    is_holiday.assign(0, false);
    cout << endl;
    PrintVector_bool(is_holiday);
    */

    // очистка
    is_holiday.clear();
    return 0;
}