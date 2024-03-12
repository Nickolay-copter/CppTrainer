#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart{
    public:
        FunctionPart(char new_operation, double new_value){
            operation = new_operation;
            value = new_value;
        }
        double Apply(double source_value) const {
            if (operation == '+'){
                return source_value + value;
            } else if (operation == '-'){
                return source_value - value;
            } else if (operation == '*') {
                return source_value * value;
            } else {
                return source_value / value;
            }
        }
        void Invert() {
            if (operation == '+'){
                operation = '-';
            } else if (operation == '-'){
                operation = '+';
            } else if (operation == '*') {
                operation = '/';
            } else {
                operation = '*';
            }
        }
    private:
        char operation;
        double value;
};
/*
2. Далее описываем сам класс в контексте методов не запполняя их
непосредственно
3. Определяем что доожен хранить класс - здесь это набобр элементарных
операций
6. Прожолжим наполнение методов сласса Function
*/
class Function{
    public:
        void AddPart(char operation, double value){
            parts.push_back({operation, value});
        };
        double Apply(double value) const{
            for (const FunctionPart& part : parts){
                value = part.Apply(value);
            }
            return value;
        };
        void Invert(){
            for (FunctionPart& part : parts){
                part.Invert();
            }
            reverse(begin(parts), end(parts));            
        };
    private:
        vector<FunctionPart> parts;
};
