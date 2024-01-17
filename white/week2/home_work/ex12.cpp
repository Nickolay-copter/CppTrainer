#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void change_capital(map<string, string>& capital_book, string& resolution, const string& country, const string& capital){
    int flag_ex = capital_book.count(country);
    if (flag_ex == 0 ){
        resolution = "Introduce new country "+ country +" with capital "+ capital;
        capital_book[country] = capital;
    } else {
        string old_capital = capital_book[country];
        if (old_capital == capital){
            resolution = "Country "+ country +" hasn't changed its capital";
        } else {
            resolution = "Country " + country +" has changed its capital from "+ old_capital + " to " + capital;
            capital_book[country] = capital;
        }
    }
}
void rename(map<string, string>& capital_book, string& resolution, const string& old_country, const string& new_country){
    bool incorrect_flag = (new_country == old_country) || (capital_book.count(old_country) == 0) || (capital_book.count(new_country) == 1);
    string tmp_capital;
    if (incorrect_flag){
        resolution = "Incorrect rename, skip";
    } else {
        tmp_capital = capital_book[old_country];
        capital_book.erase(old_country);
        capital_book[new_country] = tmp_capital;
        resolution = "Country " + old_country + " with capital " + tmp_capital + " has been renamed to " + new_country;
    }
    
}
void about(map<string, string>& capital_book, string& resolution, const string& country){

}

int main(){
    int Q, flag_ex; 
    string command;
    string old_country, new_country, new_capital;
    string resolution;
    string key_value;
    map<string, string> capital_book;
    vector<string> command_history;
    cin >> Q;
    for (int q = 0; q < Q; ++q){
        cin >> command;
        if (command == "CHANGE_CAPITAL"){
            cin >> new_country >> new_capital;
            change_capital(capital_book, resolution, new_country, new_capital);
            command_history.push_back(resolution); 
        } else if (command == "RENAME"){
            cin >> old_country >> new_country;
            rename(capital_book, resolution, old_country, new_country);
            command_history.push_back(resolution); 
        } else if (command == "ABOUT"){
            cin >> old_country;
            if (capital_book.count(old_country) == 0){
                resolution = "Country " + old_country + " doesn't exist";
            } else{
                resolution = "Country " + old_country + " has capital " + capital_book[old_country];
            }
            command_history.push_back(resolution);
        } else if (command == "DUMP"){
            if (capital_book.size() == 0){
                resolution = "There are no countries in the world";
            } else {
                resolution = "";
                for (const auto& p : capital_book){
                    resolution += p.first + "/" + p.second + " ";
                }   
            }
            command_history.push_back(resolution);
        } else{
            cout << "Такой команды нет";
        }
    }
    for (const string& ans : command_history)
        cout << ans << endl;
    return 0;
}