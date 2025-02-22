#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
   bool isVowel(char c)
      {
      string vowels = "aeoui";
      return vowels.find(c)!=string::npos;
      }
    int maxVowels(string s, int k) {
        vector<int> ps(s.size());
        if(k-1>=s.size())
           return 0;
        ps[0] = isVowel(s[0]);
        for (int i = 1;i < s.size();i++)
           {
           ps[i] = ps[i-1] + isVowel(s[i]);
           }
        int mx = ps[k-1];
        for (int i = k;i < s.size();i++)
           {
           mx = max(mx, ps[i]-ps[i-k]);
           }
        return mx;

        
    }
};
int main()
{
   string s = "abciiidef";
   int k = 3;
   Solution sol;
   cout<<sol.maxVowels(s,k);
   
   cout<<endl;
   return 0;
}