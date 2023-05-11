#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int x = 4;
    string y = "Hello";
    cout<< x<< ' '<< y;

    /* компилятор скажет что он не знает оператора вывода вектора, т.к.
    нет единого способа преобразования вектора в поток - с пробеламти/без, с запятыми/без
    vector<int> d = {1,2};
    cout<< d;
    */
    // Ввод в консоли consol input
    int a, b;
    cin >> a>>b;
    cout<< a+b<< endl; 
    
    return 0;
}