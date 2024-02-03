#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
/*
ООП призвано:
1. Предотвратить разбухание кода
2. Компактно представлять сущности
3. Масштабируемость
*/
/*
создадим собственный тип данных
*/
struct Lecture {
    string title;
    int duration;
    string author;
};

// Вложенные типы
/*
Если очередность объявления типов поменять местами,
то будет ошибка, так как здесь работает принцип
послежовательносго объявления line-by-line
*/
struct LectureTitle {
    string specification;
    string course;
    string week;
};

struct DetailedLecture {
    LectureTitle title;
    int duration;
};


void PrintLecture(const Lecture& lecture){
    cout <<
        "Title: " << lecture.title <<
        ", duration: " << lecture.duration <<
        ", author:" << lecture.author << "\n";
}

Lecture GetCurrentLecture(){
    return {"OOP", 5400, "Anton"};
}

int main(){
    Lecture lecture1, lecture2;
    lecture1.title = "OOP";
    lecture1.duration = 5400;
    lecture1.author = "Anton";
    lecture2 = {"OOP", 5400, "Anton"};
    // передача в функцию
    PrintLecture({"OOP", 5400, "Anton"}); // "как бы создали" и передали структуру
    Lecture current_lecture = GetCurrentLecture();
    // создание структур со слоденными типами
    LectureTitle title = {"C++", "White belt", "OOP"};
    DetailedLecture lecture3 = {title, 5400}; // первый вариант
    DetailedLecture lecture4 = {
        {"C++", "White belt", "OOP"},
        5400
    }; // второй вариант
    // обращение
    cout << lecture4.title.specification << "\n";
    return 0;
}