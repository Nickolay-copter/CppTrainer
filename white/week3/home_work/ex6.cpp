#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

class ReversibleString {
    public:
        ReversibleString(){
            strword = "";
        }
        ReversibleString(const string& new_strword){
            strword = new_strword;
        }
        void Reverse(){
            reverse(begin(strword), end(strword));
        }
        string ToString() const{
            return strword;
        }
    private:
        string strword;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
  
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
  
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
  
    return 0;
}