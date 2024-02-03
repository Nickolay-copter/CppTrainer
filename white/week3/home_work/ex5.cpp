#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            FirstName[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name) {
            SecondName[year] = last_name;
        }
        string GetFullName(int year) {
            LastActualValue(FirstName, year, year_first, FName);
            LastActualValue(SecondName, year, year_second, SName);
            if (FName == false && SName == false){
                return "Incognito";
            } else if (FName == false && SName == true){
                return (SecondName[year_second] + " with unknown first name");
            } else if (FName == true && SName == false){
                return (FirstName[year_first] + " with unknown last name");
            } else {
                return (FirstName[year_first] + " " + SecondName[year_second]);
            }  
        }
        string GetFullNameWithHistory(int year) {
            vector<string> years_first = HistoryActualValue(FirstName, year, FName);
            vector<string> years_second = HistoryActualValue(SecondName, year, SName);
            if (FName == false && SName == false){
                return "Incognito";
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
        bool FName, SName;
        int year_first, year_second;
        void LastActualValue(const map<int, string>& cont, const int& year, int& year_selsect, bool& Flag){
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
        vector<string> HistoryActualValue(const map<int, string>& cont, const int& year, bool& Flag){
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
};

//int main() {
//  Person person;
//  
//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeLastName(1967, "Sergeeva");
//  for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullName(year) << endl;
//  }
//  
//  person.ChangeFirstName(1970, "Appolinaria");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }
//  
//  person.ChangeLastName(1968, "Volkova");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }
//  
//  return 0;
//}
/*
int main() {
    Person person;
    person.ChangeLastName(3, "3_2nd");
    person.ChangeLastName(6, "6_2nd");

    for (int year : {3, 4, 5, 6}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(-1, "-1_1st");
    person.ChangeFirstName(2, "2_1st");

    for (int year : {-1, 0, 1, 2, 3, 6}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(-2, "-2_1st");
    person.ChangeLastName(7, "7_2nd");

    for (int year : {-3, -2, -1, 0, 1, 2, 3, 6, 7, 8}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
*/
/*
int main(){
    Person person;

    person.ChangeLastName(1960, "AAA");


    for (int year : {1900, 1960}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    return 0;
}
*/
/*
int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
*/
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}