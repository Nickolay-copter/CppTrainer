/*
Деструктор вызывается при уничтожении объекта

Назначение - откат действий, сделанных в конструкторе
и других методах
 - закрытие открытого файла
 - освобождение выделенной вручную памяти 
можно осуществлять и другие действия - например
вывод какой-то отладочной информации

На практике писать деструкторы самому приходится очень редко
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

/*
Структуры в конструкторах не нуждаются. Если нужно объявить поля по умолчанию
то можно поля проинициализировать
*/
struct Lecture{
    string title = "C++";
    int duration = 0;
};

/*
Для того чтобы сделать классы более удобными в использовании
дописывают конструкторы. 

Хотим создать маршрут между конкректными городами
Прежде нам надо было написать три строчки кода, в функции
main:
    Route route;
    route.SetSource("Moscow");
    route.SetDestination("Tuapse");

Естественный выход - написать функцию BuildRoute(),
Route BuildRoute(const string& source, const string& destination){
    Route route;
    route.SetSource(source);
    route.SetDestination(destination);
    return route;
} 
которая бы формировала маршрут - однако, такая функция выглядит искусственно
Действительно, как же назвать такую функци, которая в независимости от
названия класса и его операций внутри, - инициализировала бы его
наиболее простым методом.

Хочется того же, что умеют типы стандартной библиотеки
как например 
    vector<string> names(5);
    string spaces(10, ' ');
Поэтому нужно создать конструктор. Конструктор это специальный
метод класса у которого нет возвращаемого значечения, так как
он должен просто создать объект. Т.е. возвращаемого типа НЕТ
а название этого метода совпадает с названием КЛАССА!!!
*/
int ComputeDistance(const string& sourse, const string& destination){
    return sourse.length() - destination.length();
}

class Route{
    public:
        Route(const string& new_source, const string& new_destination){
            source = new_source;
            destination = new_destination;
            UpdateLength();
            cout << "Constructed\n";
        }
        Route() {
            // опционально можем объявить поля по умолчанию
            source = "Moscow";
            destination = "Saint Petersburg";
            UpdateLength();
            cout << "Default constructed\n";
        } // конструктор по умолчанию
        /* Деструктор ничего не возвращает*/
        ~Route(){
            cout << "Destructed\n";
        }
        void SetSource(const string& new_source){
            source = new_source;
            UpdateLength();
        }
        void SetDestination(const string& new_destination){
            destination = new_destination;
            UpdateLength();
        }
        string GetSource() const { return source;}
        string GetDestination() const {return destination;}
        int GetLength() const {return length;}
    private:
        string source;
        string destination;
        int length;
        void UpdateLength(){
            length = ComputeDistance(source, destination);  
            compute_distance_log.push_back(source + " " + destination);
            /*
            теперь нужно найти место где этот лог вывести.
            Можно вывести в отдельной функции, а можно сказать
            компилятору, что как только объект уничтожится - выведи
            весь лог вызова этой функции, для этого напишем деструктор.
            */   
        }
        /* хотим написать лог функции ComputeDistance*/
        vector<string> compute_distance_log;
};

void PrintRoute(const Route& route){
    cout << route.GetSource() << " - "<< route.GetDestination() << endl;
}

void ReverseRoute(Route& route){
    string old_source = route.GetSource();
    string old_destination = route.GetDestination();
    route.SetSource(old_destination);
    route.SetDestination(old_source);
}

void Worthless(Route route){
    cout << 2 << "\n";
    /*
    по выходу из функции вызовется деструктор
    */
}

Route GetRoute(){
    cout << 1 << "\n";
    return {};
}

int main(){
    cout << 1 << "\n";
    Worthless({}); // так как входной тип у функции определен, то можно так, компилятор поймёт, что вызывается конструктор по умолчанию
    cout << 3 << "\n";
}

