#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
   int getPrefix(int i, vector<int>& pre)
      {
      if(i<=0)
         return 1;
      return pre[i-1];
      }
   int getSuffix(int i, vector<int>& suffix)
      {
      if(i>= suffix.size()-1)
         return 1;
      return suffix[i+1];
      }
   int productExceptSelf(int i, vector<int>& pre, vector<int>& suf)
      {
      return getPrefix(i, pre)* getSuffix(i, suf);
      }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefixProduct(nums.size());
        vector<int>suffixProduct(nums.size());
        partial_sum(nums.begin(), nums.end(), prefixProduct.begin(), [](int a, int b){return a*b;});
        reverse(nums.begin(), nums.end());
        partial_sum(nums.begin(), nums.end(), suffixProduct.begin(), [](int a, int b){return a*b;});
        reverse(suffixProduct.begin(), suffixProduct.end());
        reverse(nums.begin(), nums.end());
        vector<int> ret;
        ret.reserve(nums.size());
        for (int i = 0;i < nums.size(); i++)
           {
           ret.push_back(productExceptSelf(i, prefixProduct, suffixProduct));
           }
        return ret;


        return ret;


    }
};
int main()
{
   vector<int> nums{1,2,3,4};
   Solution sol;
   auto ret = sol.productExceptSelf(nums);
   for(auto & x: ret)
      cout<<x<<' ';
   cout<<endl;
   return 0;
}