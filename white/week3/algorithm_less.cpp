#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int Min(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int Max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

void Print(const vector<int>& v, const string& title){
    cout << title << ": ";
    for (auto i : v){
        cout << i << " ";
    }
}

bool Gt2(int x){
    if(x > 2){
        return true;
    }
    return false;
}

int main() {
    cout << Min(2,3) << endl;
    cout << Max(2,3) << endl;
    // можно использовать уже готовые ффункции
    cout << min(2,3) << endl;
    cout << max(2,3) << endl;
    string s1 = "abc";
    string s2 = "bca";
    cout << min(s1,s2) << endl;
    cout << max(s1,s2) << endl;
    vector<int> v {1,3,2,4, 5};
    //сортировка
    Print(v, "init");
    /*
    Чтобы отсортировать сущность, необходимо взять начало и конец интервала 
    сортировки с помощью begin() и end() 
    */
    cout << endl;
    sort(begin(v), end(v));
    Print(v, "sort");
    // Подсчитаем количество вхождений числа
    int cnt = 0;
    for (auto i: v){
        if (i == 2){
            ++cnt;
        }
    }
    cout << endl << cnt << endl;
    //можно использовать стандартную функцию
    cout << count(begin(v), end(v), 2) << endl;
    /* 
    найти количесвто элементов больше\меньше чем что-то. Третим 
    элементом на вход данной функции надо передать функцию, которая будет 
    принимать на свой вход эдемент и возвращать true или false
    */
    cout << count_if(begin(v), end(v), Gt2) << endl;
    /*
    етсть недостаток - Gt2 - специализированы и место определение 
    данной функции далеко от места ввызова, т.е. - не наглядно, нужно искать более 
    универсальные подходы - можно написать лямбда выражение - способ написать функцию
    прямо по месту вызова "налету". Начинается с квадратных скобок - они говорят, что
    начинается лямбда-выражение
    */
    cout << count_if(begin(v), end(v), [](int x){
        if(x > 2){
            return true;
        }
        return false;
    }) << endl;
    // переменную для сравнения можно также определить
    int thr;
    cin >> thr;
    /* 
    чтобы передать значение переменной в лямбда функцию, 
    необходимо прописать её в квадратных скобках 
    */
    cout << count_if(begin(v), end(v), [thr](int x){
        if(x > thr){
            return true;
        }
        return false;
    }) << endl;
    // Простой способ увеличить элементы контейнера
    // Первый способ - через цикл for
    for(int i = 0; i < v.size(); ++i){
        ++v[i];
    }
    Print(v, "increment 1");
    /* 
    по ссылке в цикле range-based-form
    (рекомендуется именно этот подход для подобных задач). Нужно заметить
    что исподьзование ссилки в оператарах циклов  не всегда даёт выйгрыш в производительности
    Так, для пеменных типа int - это делать бессмысленно, а для тех случаев, когда
    предполаегается, что элементами являются какие-то тяжелые сущности, напремер string - то такой 
    подход уместен. Также, дописывают const если не планируется изменять итерируемую сущность
    */
    cout << endl;
    for(auto& i : v){
        ++i;
    }
    Print(v, "increment 2");
    return 0;
}
/*
лямбда выражения используются для записи однострочников, чтобы не писать 
узкоспециализированные функции
*/