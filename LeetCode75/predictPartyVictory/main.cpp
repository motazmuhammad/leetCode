#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<stack>
#include<regex>
#include<sstream>
#include <queue>
#include <list>
#include <deque>
using namespace std;
class Solution
   {
   public:

      string predictPartyVictory(string s)
         {
         deque<int> R;
         deque<int> D;
         for (int i = 0;i < s.size();i++)
            {
            if(s[i]=='D')
               D.push_back(i);
            else
               R.push_back(i);
            }
         int n = s.size();
         while (!R.empty() && !D.empty())
            {
            auto rf=R.front();
            auto df=D.front();
            if (rf < df)
               {
               D.pop_front();
               R.pop_front();
               R.push_back(n);
               n++;
               }
            else
               {
               D.pop_front();
               R.pop_front();
               D.push_back(n);
               n++;

               }
            }
         return D.empty()?"Radiant":"Dire";
         }
   };
int main()
   {
   string s = "RD";
   Solution sol;
   auto ret = sol.predictPartyVictory(s);
   cout << ret;
   cout << endl;
   return 0;
   }