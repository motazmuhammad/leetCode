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
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, m+n));
        dp[0][0] = !(s[0]==t[0]);

        for(int i = 1 ;i<n;i++)
           {
           if(s[i]==t[0])
            dp[i][0] = i;
           else
              dp[i][0] = 1+dp[i-1][0];
           }
        for(int i = 1;i<m;i++)
           {
           if(t[i]==s[0])
              dp[0][i] = i;
           else
           dp[0][i] = 1+dp[0][i-1];;
           }
        for(int i = 1 ;i<n;i++)
           for (int j = 1;j < m;j++)
              {
              if (s[i] == t[j])
                 {
                 dp[i][j] = dp[i-1][j-1];
                 }
              else
                 {
                 dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
                 }
              }
        return dp[n-1][m-1];
    }
};
int main()
   {
   std::vector<int>v{ 1,1000 };
   Solution sol;
   int k = 9;
   int n = 60;
   string s = "horse";
   string t = "ros";
   auto ret = sol.minDistance(s, t);
   cout<<ret<<endl;
   return 0;
   }