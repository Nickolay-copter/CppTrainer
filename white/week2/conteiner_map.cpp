#include<iostream>
#include<map>
#include<vector>
using namespace std;

void PrintMap(const map<int, string>& m){
    cout << "Size = " << m.size() << endl;
    for (auto item : m){
        cout << item.first << ": " << item.second << endl;
    }
    
}

void PrintReversedMap(const map<string, int>& m){
    cout << "Size = " << m.size() << endl;
    for (auto item : m){
        cout << item.first << ": " << item.second << endl;
    } 
}

/* Функция написана оптимальнее: очередная пара ключ-значение теперь не
копируется в переменную item, теперь компилятор видит, что это константная ссылка на "какой-то" конкретный
тип */
void PrintReversedMapMod(const map<string, int>& m){
    cout << "Size = " << m.size() << endl;
    for (const auto& item : m){
        cout << item.first << ": " << item.second << endl;
    } 
}

map<string, int> BuildReverseMap(const map<int, string>& m){
    map<string, int> result;
    for (auto item : m)
        result[item.second] = item.first;
    return result;
}

int main(){
    map<int, string> events;
    events[1950] = "Straustrup's birth";
    events[1941] = "Ritchi's birth";
    events[1970] = "UNIX birth's";
    // Отличительное свойство map - ключи храняться сортированными
    PrintMap(events);
    // обращение в словаре по ключам
    cout << events[1950] << endl;
    // удаление по ключам
    events.erase(1970);
    PrintMap(events);
    // там где не помогут вектора - построить перевёрнутый словарь
    PrintReversedMap(BuildReverseMap(events));
    map<string, int> events_for_year = BuildReverseMap(events);
    cout << events_for_year["Straustrup's birth"];
    // Словари часто называют ассоциативными массивами
    map<string, int> m = {{"ones", 1}, {"two", 2}, {"three", 3}};
    PrintReversedMapMod(m);
    // удаление
    m.erase("three");
    /* Метод erase можно вызвать от любого числа. Если оно являлось ключом словаря, 
    этот ключ удалится вместе со своим значением. В противном случае словарь не изменится.*/
    PrintReversedMapMod(m);
    vector<string> words = {"one", "two", "one"};
    // хотим посчитать уникальные значения значения
    // тогда можно использовать словарь
    map<string, int> conuters;
    /*Воспользуемся константной ссылкой, для того, чтобы 
    лишний раз не осуществлять глубокое копирование в word*/
    for (const string& word : words){
        /* для словаря определён метод count - указывает на то
        сколько раз встречается ключ в словаре, поскольку ключи
        уникальные там будет либо 0 либо 1
        if (conuters.count(word) == 0){
            conuters[word] = 1;
        } else{
            ++conuters[word];
        }
        однако можно написать код оптимальнее: так как, как только
        произошло обращение, компилятору сразу нужно создать пару ключ-значение,
        значение по умолчанию 0 (так как целое значение по умолчанию - это 0)
        */
        ++conuters[word];
    }
    PrintReversedMapMod(conuters);
    // ниже приведен пример как по первому обращению в словаре создаётся значение по умолчанию
    map<string, int> dict;
    dict["a"];
    PrintReversedMapMod(dict);
    // сгруппируем слова по первой букве
    vector<string> gword = {"one", "two", "three"};
    map<char, vector<string>> wgroup;
    for (const string& w : gword){
        wgroup[w[0]].push_back(w);
    }
    for (const auto& item : wgroup){
        cout << item.first << ": "<< endl;
        for (const string& word : item.second){
            cout << "   " << word << endl;
        }
    }
    /*
    Что можно делать с помощью словаря:
    - обращаться к элементам при помощи квадратных скобочек, при это
    если не было ключа то он добавится
    - удалять элементы с помощью метода erase()
    - можно проверять наличие в словаре ключа с помощью метода count()
    - выводить в стандартынй поток вывода словари с помощь for
    */
    /*
    В с++ вышел новый стандарт c++ 17. Не всегда изменения в стандартах  доходят до
    конкретных компиляторов. Но всё же некоторые изменения можно посмотреть уже сейчас
    Так например на ресурсе gcc.godbolt.org можно попробовать нововведения.
    */
    return 0;
}