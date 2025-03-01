// Make String a Subsequence Using Cyclic Increments
// Problem link:
// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
         if(str1.size() < str2.size()) return false;
         int i = 0, j = 0;
          while(i < str2.size()){
              while(j < str1.size()){
                  if(str1[j] == str2[i]){
                       i++;
                       j++;
                       break;
                  }
                  else if(str1[j] == 'z' && str2[i] == 'a'){
                      i++;
                      j++;
                      break;
                  }
                  else if((char)(((int)str1[j]) + 1) == str2[i]) {
                      i++;
                      j++;
                      break;
                  }
                 j++;
              }
              // if entire string1 is traversed and string2 is not yet traversed entirely that means str2 can't be subsequence of str1.
              if((j == str1.size() && i < str2.size())) return false;
          }
            return true;
    }
};


/*
List of edge case to test your solution:
str1 = "abc", str2 = "ad"
str1 = "zc", str2 = "ad"
str1 = "ab", str2 = "d"
str1 = "om" str2 = "nm"  
str1 = "eao" str2 = "ofa"
str1 = "abc" str2 = "abcd"
str1 = "at" str2 = "se"
str1 = "b" str2 = "c"
*/