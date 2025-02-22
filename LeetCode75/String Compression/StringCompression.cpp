#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
       if(chars.size()<2)
          return chars.size();
        int i = 0 , j = 0;
        while (j < chars.size())
           {
           int cnt = 0;
           char start = chars[j];
           while ( j <chars.size() && chars[j] == start )
              {
              cnt++;
              j++;
              }
           chars[i] = start;
           i++;
           if(cnt>1)
              { 
           string reps = to_string(cnt);
           for (auto& x : reps)
              {
              chars[i] = x;
              i++;
              }
              }

           }
        return i;
        
    }
};
int main()
{
   vector<char> s{ 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
   Solution sol;
   int n = sol.compress(s)<<' ';
   for (int i = 0;i < n;i++)
      {
      cout<<s[i];
      }
   cout<<endl;
   return 0;
}