#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int ComputeDistance(const string& sourse, const string& destination);

/*
Чтобы постоянно не вычислять по функции
ComputeDistance добавляем поле length - длина
маршрута. Может так случиться, что мы зыхотим поменять один из городов,
не забудем ли мы поменять length? Для того,
чтобы минимизтвароть такие ошибки, есть средство - 
запрет прямого доступа к нашим полям в структуре.
Т.е. сделать эти поля приватными написав перед списком полей
private. Теперь к этим полям нет доступа снаружи класса

По сути структура получилась бесполезной - мы не можем
не прочитать с неё не записать. Чтобы можно было проволить некоторые операции
нам помогут МЕТОДЫ. для этого добавим публичную секцию. Поля, в пределях
класса находятся в прямой видимости, по этому к ним можно обращаться на прямую
*/
struct Route{
    public:
        string GetSource() { return source;}
        string GetDestination() {return destination;}
        int GetLength() {return length;}
    private:
        string source;
        string destination;
        int length;
};
/*
Отличие методов от функций:
1. методы вызываются в контексте конкретного объекта
2. имеют доступ к приватным полям
3. методы описаны внутри класс и классы разрешают обращаться
к приватным полям
*/
/*
По сути что было описано выше это уже описанный КЛАСС
по этому так и запишем:
Нужно добавить возможность изменять поля. Допишем два публичных 
метода. Секции public и private в определении класса могут повторяться 
любое количество раз и располагаться в любом порядке.
*/
class Route{
    public:
        void SetSource(const string& new_source){
            source = new_source;
            UpdateLength();
        }
        void SetDestination(const string& new_destination){
            destination = new_destination;
            UpdateLength();
        }
        string GetSource() { return source;}
        string GetDestination() {return destination;}
        int GetLength() {return length;}
    private:
        string source;
        string destination;
        int length;
        void UpdateLength(){
            length = ComputeDistance(source, destination);     
        }
};

int main(){
    Route route;
    route.SetSource("Moscow");
    route.SetDestination("Dubna");
    int destination_name_length = route.GetDestination().length();
    cout << route.GetLength() << endl;
    cout << "Route from " <<
        route.GetSource() << " to " <<
        route.GetDestination() << " is " <<
        route.GetLength() << " meters long";
    return 0;
}
/*
* Структура (struct) - набор публичных полей;
    - используем когда не нужно контролировать содержание
* Класс (class) - скрывает данные, предоставляя определенный
интерфейс доступа к ним
    - использум когда поля связаны друг с другом и 
    эту связь нужно контроллировать
*/
