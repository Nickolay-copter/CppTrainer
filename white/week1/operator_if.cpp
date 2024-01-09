#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    /* Если в теле оператора имеется только одна 
    операция, то можно обойтись без фигурных скобок.
    Аналогично, если у нас имеется альтернатиное условие.
    */
    if (a == b)
        cout << "Equal"<< endl;
    else
        cout << "Not equal"<< endl;
    
    if (a == b) {
        cout << "Equal"<< endl;
        cout << a <<" "<< b << endl;
    }
    else {
        cout << "Not equal"<< endl;
        cout << a <<" "<< b << endl;
    }

    int c = -1;
    /* В отличие от языков java, Python отступ в С++
    не определяют вложенность операций в теле операторов if и else.
    Если не поставить фигурные скобки, то else будет воспринят
    компилятором как оператор относящийся к внутреннему if
    */
    if (c >= 0) {
        if (c > 0)
            cout << "Positive";
    }
    else
        cout << "Negative";
    return 0;    
}