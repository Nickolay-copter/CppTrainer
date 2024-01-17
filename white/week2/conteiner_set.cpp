#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

void PrintSet(const set<string>&);

int main(){
    map<string, bool> is_famous_person;
    is_famous_person["Stroustrup"] = true;
    is_famous_person["Ritchie"] = true;
    /* Такое представление людей избыточно - так как данный объект
    и так включает в себя только знаменитых людей, поэтому чтобы избежать 
    такой избыточности используют контейнер set - множество*/
    set<string> famous_person;
    /*  для добавления используем метод insert()*/
    famous_person.insert("Stroustrup");
    famous_person.insert("Ritchie");
    famous_person.insert("Ritchie"); // гарантируется уникальность элементов - т.е. дублирования не будет
    PrintSet(famous_person);
    /* Видно что множество не сохраняет порядок элементов, с++ гарантирует
    что элементы хранятся в отсортированном порядке, гарантируется уни кальность 
    элементов, в отдичие от вектора*/
    famous_person.insert("Nickolay");
    PrintSet(famous_person);
    // Удаление тем же методом как и в словаре
    famous_person.erase("Nickolay");
    PrintSet(famous_person);

    // Даже если мы добавим несколько раз одно и тоже название, оно сохранится только один раз
    set<string> month_names = {"Jan", "Mar", "Feb", "Mar"};
    // Видно, что строки отсортировались как ключи в словаре
    PrintSet(month_names);
    // Строки можно сравнивать как и другие контейнеры
    set<string> month_names_1 = {"Mar", "Jan", "Feb"};
    cout << (month_names_1 == month_names) << endl;
    // Есть ли конкретный метод
    cout << month_names.count("Jan") << endl;
    // Ассоциативные контейнеры - map, set
    // Множество из вектора
    vector<string> v = {"a", "b", "a"};
    /* Т.е. не надо перебирать значения в цикле. Достаточно указать начальное
    и конечное значение в методе*/
    set<string> s(begin(v), end(v));
    PrintSet(s);
    /*Аналогично создаётся вектор из множества. Таким образом, все контейнеры 
    создаются друг из драга*/ 
    return 0;
}

void PrintSet(const set<string>& s){
    cout << "Size = " << s.size() << endl;
    for (const auto& x : s){
        cout << x << endl;
    }   
}