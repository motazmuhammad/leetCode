#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<stack>
using namespace std;
class Solution
   {
   public:
      vector<int> asteroidCollision(vector<int>& asteroids)
         {
         stack<int> s;
         for (auto& x : asteroids)
            {
               if(x>0)
                  s.push(x);
               else
                  {
                  if(s.empty())
                     s.push(x);
                  else
                     {
                     auto current = s.top();
                     if(current<0)
                        s.push(x);
                     else
                        { 
                        while (!s.empty()&& current>0 && current<abs(x))
                           {
                           s.pop();
                           if(!s.empty())
                              current = s.top();
                           }
                        if (!s.empty() && current == abs(x) )
                           {
                           s.pop();
                           }
                        if (!s.empty() && current < 0)
                           {
                           s.push(x);
                           }
                        }
                     }

                  }


            }
         vector<int> ret;
         while (!s.empty())
            {
            ret.push_back(s.top());
            s.pop();
            }
         reverse(ret.begin(), ret.end());
         return ret;
         }
   };
int main()
   {
   vector<int> nums{ -2,-1,1,2 };
   int k = 3;
   Solution sol;
   auto ret = sol.asteroidCollision(nums);
   for (auto& x : ret)
      cout << x << ' ';
   cout << endl;
   return 0;
   }