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
   void Combination(int k, int n, vector<vector<int>>& ret, vector<int> current, vector<bool>visited)
      {
      if (k < 0)
         return;
      if (n < 0)
         return;
      if (k == 0 && n == 0)
         {
         sort(current.begin(), current.end());
         auto it = find(ret.begin(), ret.end(), current);
         if (it == ret.end())
            ret.push_back(current);
         }
      for (int i = 1;i <= 9;i++)
         {
         if(!visited[i])
            { 
            visited[i] = true;
            current.push_back(i);
            Combination(k - 1, n - i, ret, current, visited);
            current.pop_back();
            }
         }

      }
   public:
      vector<vector<int>> combinationSum3(int k, int n)
         {
         vector<bool>visited(10, false);
         vector<vector<int>> ret;
         vector<int> current;
         Combination(k, n, ret, current, visited);
         return ret;
         }
   };
int main()
   {
   string s = "RD";
   std::vector<int>v{ 1,1000 };
   Solution sol;
   int k = 9;
   int n = 60;
   auto ret = sol.combinationSum3(k, n);
   for (auto& x : ret)
      {
      for (auto& y : x)
         cout << y << ' ';
      cout << endl;
      }
   return 0;
   }