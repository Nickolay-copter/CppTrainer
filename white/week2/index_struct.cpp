#include<map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Person{
    string name;
    string surname;
    int age;
};
vector<Person> GetMoscowPopulation();
void PrintPopulationSize(vector<Person> p){
    cout << "There are " << p.size() <<
    " people in Moscow"<< endl;
}
int main() {
    //vector<Person> staff;
    //staff.push_back({"Ivan", "Ivanov", 25});

    vector<Person> people = GetMoscowPopulation();
    PrintPopulationSize(people);
    return 0;
}
