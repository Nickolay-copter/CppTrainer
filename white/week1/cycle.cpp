#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n > 0){
        int sum = 0;
        while (n > 0){
            sum += n;
            --n;
        }
        cout << sum << endl;
    }
    else
        cout << "You must enter positive number"<< endl;

    // Ниже будет представлен кусок интерактивное программы
    srand(time(NULL));
    int R = rand()%100;
    int RU;

    /*
    В том случае когда надо сначала выполнить действие
    а потом проверить условие, используется конструкция
    do {} - while() 
    */
    do
    {
        cout<< "PC guess the number. Guess his: "<< endl;
        cin >> RU;
        if (RU > R)
            cout << "Your number must be less"<< endl;
        else if (RU < R)
            cout << "Your number must be more"<< endl;
        else
            cout << "You are right";
    } while (RU != R);
    return 0; 

}
