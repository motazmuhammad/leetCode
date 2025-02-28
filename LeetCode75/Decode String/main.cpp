#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<stack>
#include<regex>
#include<sstream>
using namespace std;
class Solution
   {
   public:
      bool GetString(string& s)
         {

         int i = 0;
         string ret = "";
         while (s[i] != ']')
            {

            i++;
            if (i >= s.size())
               return false;
            }
         s.erase(s.begin()+i);
         i--;
         while (s[i] != '[')
            {
            ret+=s[i];
            i--;
            if(i<0)
               return false;
            }
         s.erase(i, ret.size()+1);
         reverse(ret.begin(), ret.end());
         string n = "";
         i--;
         while (isdigit(s[i]))
            {
            n+=s[i];
            i--;
            if(i<0)
               break;
            }
         reverse(n.begin(), n.end());
         int num = stoi(n);
         s.erase(i+1, n.size());
         string temp = "";
         for (int i = 0;i < num;i++)
            {
            temp+=ret;
            }
         s.insert(i+1, temp);
         return true;





         }
      string decodeString(string s)
         {
         while (GetString(s))
            {

            }
         return s;
         }
   };
int main()
   {
   string s = "3[a2[c]]";
   Solution sol;
   auto ret = sol.decodeString(s);
   cout << ret;
   cout << endl;
   return 0;
   }