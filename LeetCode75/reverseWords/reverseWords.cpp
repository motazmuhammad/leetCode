#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
        stringstream ss;
        string current;
        ss<<s;
        while (ss >> current)
           {
           
           words.push_back(current);
           }
        if(words.size()==0)
           return "";
        if (words.size() == 1)
           {
           return words[0];
           }
        reverse(words.begin(), words.end());
        string ret = "";
        for (int i = 0;i < words.size()-1;i++)
           {
           ret+=words[i];
           ret+=' ';
           }
        ret+=words.back();
        return ret;
    }
};
int main()
{
   string s = "the sky is blue";
   Solution sol;
   cout<<sol.reverseWords(s);
   return 0;
}