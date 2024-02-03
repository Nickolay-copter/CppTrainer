#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class SortedStrings {
    public:
        void AddString(const string& s) {
            string_bag.push_back(s);
            sort_string_bag();
        }
        vector<string> GetSortedStrings() {return string_bag;}
    private:
        vector<string> string_bag;
        void sort_string_bag(){sort(begin(string_bag), end(string_bag));}
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
      cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;
    
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    return 0;
}