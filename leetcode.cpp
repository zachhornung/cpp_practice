#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        check(s);
        return s;
    }
    void check(string &s){
        for (int i = 0; i < s.size(); i++){
            if (s[i]+32 == s[i+1] | s[i] == s[i+1]+32){
                s.erase(i,2);
                check(s);
                break;
            }
        }
    }
};
int main(){
  Solution s;
  cout << s.makeGood("bBbBbBbbabyGgGgGoats") << endl;
  cout << "hello world" <<endl;
  return 1;
};