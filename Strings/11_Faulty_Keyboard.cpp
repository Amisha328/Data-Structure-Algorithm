// Faulty Keyboard
// Problem link:
// https://leetcode.com/contest/weekly-contest-357/problems/faulty-keyboard/

class Solution {
public:
    string finalString(string s) {
         string ans = "";
          int pos = 0;
          for(int i = 0; i < s.size(); i++){
              if(s[i] == 'i'){

                    reverse(ans.begin(), ans.end());
                    // cout<<"ans = "<<ans<<endl;
              }
              else
               {
                    ans += s[i];
                    // cout<<"ans = "<<ans<<endl;
               }
          }
          return ans;
    }
};