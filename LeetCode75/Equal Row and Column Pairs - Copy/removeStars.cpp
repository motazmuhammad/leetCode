#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include< unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (auto& x : s)
           {
           if (x == '*')
              {
              st.pop();
              }
           else
              {
              st.push(x);
              }
           }
        string ret = "";
        while (!st.empty())
           {
           auto temp = st.top();
           st.pop();
           ret+=temp;
           }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
   string s = "leet**cod*e";
   int k = 4;
   Solution sol;
   cout<<sol.removeStars(s);
   
   cout<<endl;
   return 0;
}