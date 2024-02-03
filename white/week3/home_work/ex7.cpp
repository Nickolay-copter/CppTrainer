#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

string GetName(map<int, string> name, const int& key){
    return name[key];
}

void DeleateRepeat(vector<string>& cont_hist){
    int size_history = cont_hist.size();
    int i = 0;
    while (i <= (size_history - 2)){
        if (cont_hist[i] == cont_hist[i+1]){
            cont_hist.erase(cont_hist.begin() + i);
            --i;
        }
        ++i;
        size_history = cont_hist.size();                  
    } 
}

string Resolution(vector<string>& data_cont){
    string str;
    DeleateRepeat(data_cont);
    if (data_cont.size() == 1){
        str = data_cont[0];
    } else {
        reverse(data_cont.begin(), data_cont.end());
        str = data_cont[0] + " (";
        data_cont.erase(data_cont.begin());
        for (const auto& item : data_cont){
            str += item + ", ";
        }
        str.erase(str.end()-2, str.end());
        str += ")";// with unknown first name";
    }
    return str;
}

vector<string> HistoryActualValue(map<int, string> cont, int year, bool& Flag){
    vector<string> cont_hist;
    for (const auto& item : cont){
        if (item.first <= year){
            cont_hist.push_back(item.second);
        }
    }
    int size_history = cont_hist.size();
    if (size_history == 0){
        Flag = false;
    } else {
        Flag = true; 
    }
    return cont_hist;
}

class Person {
    public:
        Person(const string& first_name, const string& last_name, const int& year){
            FirstName[year] = first_name; 
            SecondName[year] = last_name;
            year_born = year;
        }
        void ChangeFirstName(int year, const string& first_name) {
            if (year != year_born){
                FirstName[year] = first_name;
            }
        }
        void ChangeLastName(int year, const string& last_name) {
            if (year != year_born){
                SecondName[year] = last_name;
            }
        }
        string GetFullName(int year) const {
            int year_first, year_second;
            bool FName, SName;
            LastActualValue(FirstName, year, year_first, FName);
            LastActualValue(SecondName, year, year_second, SName);
            
            if (FName == false && SName == false){
                return "No person";
            } else if (FName == false && SName == true){
                return (GetName(SecondName, year_second) + " with unknown first name");
            } else if (FName == true && SName == false){
                return (GetName(FirstName, year_first) + " with unknown last name");
            } else {
                return (GetName(FirstName, year_first) + " " + GetName(SecondName, year_second));
            } 
        }
        string GetFullNameWithHistory(int year) const {
            bool FName, SName;
            vector<string> years_first = HistoryActualValue(FirstName, year, FName);
            vector<string> years_second = HistoryActualValue(SecondName, year, SName);
            if (FName == false && SName == false){
                return "No person";
            } else if (FName == false && SName == true){
                return Resolution(years_second) + " with unknown first name";
            } else if (FName == true && SName == false){
                return Resolution(years_first) + " with unknown last name";
            } else {
                return Resolution(years_first) + " " + Resolution(years_second);
            }  
        }
    private:
        map<int, string> FirstName, SecondName;
        int year_born;
        void LastActualValue(const map<int, string>& cont, const int& year, int& year_selsect, bool& Flag) const {
            vector<int> v_year;
            for (const auto& item : cont){
                v_year.push_back(item.first);
            }

            if (v_year.size() == 0){
                Flag = false;
            } else if (v_year.size() == 1){
                if (v_year[0] <= year){
                    year_selsect = v_year[0]; 
                    Flag = true;
                } else {
                    Flag = false;
                    year_selsect = year;
                }
            } else{
                for (int i = 0; i < v_year.size()-1; ++i){
                    if (v_year[i] > year){
                        Flag = false;
                        year_selsect = year;
                        break;
                    } else if (v_year[i] <= year && v_year[i+1] > year){
                        year_selsect = v_year[i];
                        Flag = true;
                        break;
                    } else {
                        year_selsect = v_year[i+1];
                        Flag = true;
                    } 
                }
            }
        }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}