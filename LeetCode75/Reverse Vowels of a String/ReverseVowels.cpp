#include <iostream>
#include <vector>
using namespace std;

class Solution {
   bool isVowel(char c)
      {
      c = tolower(c);
      string vowels = "aeiou";
      auto it = vowels.find(c);
      return it!=string::npos;
      }
   string GetVowels(const string& s)
      {
      string ret = "";
      for (auto& x : s)
         {
         if(isVowel(x))
            ret+=x;
         }
      return ret;
      }
public:
    string reverseVowels(string s) {
        auto vowels = GetVowels(s);
        for (auto& x : s)
           {
           if (isVowel(x))
              {
              x = vowels.back();
              vowels.pop_back();
              }
            }
        return s;
    }
};
int main()
{
   string s = "";
   Solution sol;
   cout<<sol.reverseVowels(s);
   return 0;
}