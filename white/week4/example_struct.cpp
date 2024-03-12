#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Day{
    int value;
    Day(int new_value){
        value = new_value;
    }
};

struct Month{
    int value;
    Month(int new_value){
        value = new_value;
    }
};

struct Year{
    int value;
    Year(int new_value){
        value = new_value;
    }
};


struct Date {
    int day;
    int month;
    int year;
    // Создадим конструктор
    Date(Day new_day, Month new_month, Year new_year){
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& date){
    cout << date.day << " "<< date.month << " "<< date.year << endl;
}

int main(){
    Date date = {Day{1}, Month{1}, Year{2017}}; 
    Date date1 = {{1}, {1}, {2017}};
    Date date3 = {Day(1), Month(1), Year(2017)};
    /*
    Следующий вариант объявления структуры будет возможен
    из-за того, что конструкторы типов Day, Month, Year
    могут неявно преобразовывать тип. Соответственно, зная,
    что конструктор типа Date может принимать на вход конструкторы 
    своих аргументов, можно ожидать что произойдёт неявное преобразование
    типов
    */
    Date date2 = {1,1,2017};
    PrintDate(date);
    return 0;
}