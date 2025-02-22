#include <iostream>
#include<vector>


#include <vector>
#include <climits> // For INT_MAX
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       if(nums.size()<3)
          return false;
      std::vector<int> lm(nums.size());
      std::vector<int> rm(nums.size());
      int mn = INT_MAX;
      int mx = INT_MIN;
      
      partial_sum(nums.begin(), nums.end(), lm.begin(), [](int a, int b){return min(a,b); });
      reverse(nums.begin(), nums.end());
      partial_sum(nums.begin(), nums.end(), rm.begin(), [](int a, int b){return max(a,b); });
      reverse(nums.begin(), nums.end());
      reverse(rm.begin(), rm.end());
      for (int i = 1; i < nums.size() - 1;i++)
         {
         int left = lm[i-1];
         int current = nums[i];
         int right = rm[i+1];
         if (left < current && current < right)
            {
            return true;
            }
         }
      return false
    }
};
int main()
{
   vector<int> nums{1,2,0,3};
   Solution sol;
   auto ret = sol.increasingTriplet(nums);;

   return 0;
}