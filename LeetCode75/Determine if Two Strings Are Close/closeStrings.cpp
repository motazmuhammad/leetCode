#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<unordered_set>
#include<set>
#include<unordered_map>
using namespace std;
class Solution {
   unordered_set<char> GetChars(string& s)
      {
      unordered_set<char> ret(s.begin(), s.end());
      return ret;
      }
   vector<int> GetFreqs(string& s)
      {
      unordered_map<char, int> m;
      for(auto&x:s)
         m[x]++;
      vector<int> ret;
      for(auto&x:m)
         ret.push_back(x.second);
      return ret;
      }
   bool AreCharsSame(unordered_set<char>& a, unordered_set<char>& b)
      {
      for (auto& x : a)
         {
         if(b.find(x)==b.end())
            return false;
         }
      return true;
      }
   bool AreFreqsSame(vector<int>& a, vector<int>& b)
      {
      if(a.size()!=b.size())
         return false;
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      for (int i = 0;i < a.size();i++)
         {

         if(a[i]!=b[i])
            return false;
         }
      return true;
      }
   
public:
    bool closeStrings(string word1, string word2) {
      auto c1= GetChars(word1);
      auto c2 = GetChars(word2);
      if(!AreCharsSame(c1,c2))
         return false;
      auto freq1 = GetFreqs(word1);
      auto freq2 = GetFreqs(word2);
      if(!AreFreqsSame(freq1, freq2))
         return false;
      return true;

      
    }
};
int main()
{
   vector<int> nums{1,2,2,1,1,3};
   int k = 3;
   Solution sol;
   cout<<sol.uniqueOccurrences(nums);
   
   cout<<endl;
   return 0;
}