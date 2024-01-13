#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

// использование пространства имен бибилиотеки chrono
using namespace std::chrono;

struct Person{
    string name;
    string surname;
    int age;
};
vector<Person> GetMoscowPopulation();

// Медленно работает
void PrintPopulationSize_slow(vector<Person> p){
    cout << "There are " << p.size() <<
    " people in Moscow"<< endl;
}

/* Рабтает быстрее. Однако, известно, что по ссылке передают 
в тех случаях, если хотят изменить фактическое значение передаваемого
параметра. Поэтому это может ввести в заблуждение, что функция которая
что-то выводит вносит изменения - т.е. написание ссылки несёт также и информативный
характер и упорядочивает предствление кода программистом. Также если мы хотим обойтись без
создания промежуточной переменной people в функции main то такой код не заработает, так как
по ПРАВИЛАМ С++ результат выполнения функции не может быть передан по ссылке в другу
функцию напрямую*/
void PrintPopulationSize_fast(vector<Person>& p){
    cout << "There are " << p.size() <<
    " people in Moscow"<< endl;
}

/* Решает вышеизложенные проблемы.
- лишнее копирование
- не вводим в заблужение пользователя
- можем не создавать промежуточную переменную
- защищает от случайного изменения параметров функций
*/

void PrintPopulationSize(const vector<Person>& p){
    cout << "There are " << p.size() <<
    " people in Moscow"<< endl;
}
int main() {
    
    //vector<Person> staff;
    //staff.push_back({"Ivan", "Ivanov", 25});
    // auto start = steady_clock::now();
    vector<Person> people = GetMoscowPopulation();
    // auto finish = steady_clock::now();
    // cout << "GetMoscowPopulation"
    //   << duration_cast<milliseconds>(finish - start).cout() << "ms"
    PrintPopulationSize(people);
    return 0;
}

/* #include <chrono> бибилиотека для замера вермени*/

/* Если в функцию PrintPopulationSize_* передавать не ссылки а значения
она будет работать дольше, так как если передавать значения, то происходит полное 
глубокое копирование*/
