#include <iostream>
using namespace std;
class Solution {
public:
   bool isDivisor(const string& s, const string& prefix)
      {
      int sl= s.length();
      int prel = prefix.length();
      if(sl%prel != 0)
         return false;
      int rep = sl/prel;
      string temp = "";
      for (int i = 0;i < rep;i++)
         {
         temp+=prefix;
         }
      return (temp == s);
      }

    string gcdOfStrings(string str1, string str2) {
    if(str1.length()>str2.length())
       return gcdOfStrings(str2, str1);
    string prefix = "";
    string ret = "";
    for (int i = 0;i < str1.size();i++)
       {
       prefix+=str1[i];
       if (isDivisor(str1, prefix) && isDivisor(str2, prefix))
          {
          ret = prefix;
          }
       }
    return ret;   
    }
};
int main()
{
   string w1="LEET", w2="CODE";
   Solution sol;
   cout<<sol.gcdOfStrings(w1,w2)<<endl;;
   return 0;
}