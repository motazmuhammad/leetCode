#include <iostream>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1it = 0;
        int w2it = 0;
        string ret = "";
        while (w1it < word1.size() || w2it < word2.size())
           {
           if(w1it<word1.size())
              {
              ret+=word1[w1it];
              w1it++;
              }
           if (w2it < word2.size())
              {
              ret+=word2[w2it];
              w2it++;
              }

           }
        return ret;
    }
};
int main()
{
   string w1="abc", w2="pqr";
   Solution sol;
   cout<<sol.mergeAlternately(w1,w2);
   return 0;
}