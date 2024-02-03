#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int ComputeDistance(const string& sourse, const string& destination){
    return sourse.length() - destination.length();
}

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


int main(){
    Route route;
    route.SetSource("Moscow");
    route.SetDestination("Tuapse");
    PrintRoute(route);
    ReverseRoute(route);
    PrintRoute(route);
    cout << route.GetLength();
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

