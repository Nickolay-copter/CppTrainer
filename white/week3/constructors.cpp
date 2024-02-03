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
    /*
    Параметризованный конструктор, который помогает создать объект с кон
    кретными названиями этих городов т.е. создать объект по этим параметрам.
    
    Однако, теперь не будет работать синтаксис, с объявлением "произвольных" полей, т.е.
    не будет работать синтаксис

    Route var_route;

    Так как было "сказано компилятору" - я понимаю и беру на себя объявление
    переменных этого типа

    Если мы всётаки хотим уметь создавать объект не указывая конкретные города,
    то допишем Route{}
    */
        Route(const string& new_source, const string& new_destination){
            source = new_source;
            destination = new_destination;
            UpdateLength();
        }
        Route() {
            // опционально можем объявить поля по умолчанию
            source = "Moscow";
            destination = "Saint Petersburg";
            UpdateLength();
        } // конструктор по умолчанию
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
        }
};
/*
Компилятор будет ругаться используемый метод класса не 
объявить константным, из-за того, что функция PrintRoute()
принимает метод по канстантной ссылке - т.е. предполагается, что 
класс никак редактируется. В то же время в этой функции вызывается
метод, у которого не ВЫСТАВЛЕНО ограничение на редактируемость входного
аргумента. Для этого необходимо объявить меттоды константными

Если мы попытаемся изменить метод SetSource на константный. То компилятор
выдаст ошибку, т.к. метод константный, но он изменяет объект. Так де будут ошибки
с вызовом метода UpdateLength() - так как вызывается из константного
метода - неконстантный метод. Общая ошибка обозначающая проблемы с 
константностью discars qualifires.
*/
void PrintRoute(const Route& route){
    cout << route.GetSource() << " - "<< route.GetDestination() << endl;
}

void ReverseRoute(Route& route){
    string old_source = route.GetSource();
    string old_destination = route.GetDestination();
    route.SetSource(old_destination);
    route.SetDestination(old_source);
}

Route GetRoute(bool is_empty){
    if (is_empty == true){
        return {};
    } else{ 
        return {"Zvenogorod", "Istra"};
    }
}

int main(){
    vector<string> names(5);
    string spaces(10, ' ');
    Route route_custom; // конструктор по умолчанию
    Route route("Moscow", "Tuapse");

    PrintRoute(Route());
    /* Компилятор видит, что функция принимает объект типа Route,
    компилятор поймёт, что так будет вызван конструктор по умолчанию
    */
    PrintRoute({});
    // Аналогично
    PrintRoute(Route("Zvenogorod", "Istra"));
    PrintRoute({"Zvenogorod", "Istra"});

    vector<Route> routes;
    routes.push_back({"Zvenogorod", "Istra"});

    Lecture lecture;
    cout << lecture.title << " " << lecture.duration << "\n";

    /*
    Так как поля заданы по умолчанию, можно недозадавать поля
    */
    Lecture lecture1 = {"OOP"};
    return 0;
}

/*
Методы могут быть:
- константными (не изменяют обект),
в контексте которого вызваны
- неконстантными (изменяют оюъект)

По константной ссылке на объект можно вызвать только констнантный
метод

По неконстантной ссылке можно вызвать любой метод
*/



