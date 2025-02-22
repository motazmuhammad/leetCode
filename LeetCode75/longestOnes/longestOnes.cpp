#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, num_zeros = 0;
        int mx = 0;
        int current =0;
        for (int r = 0;r < nums.size();r++)
           {
           if(nums[r])
              {
              mx = max(mx, r+1-l);
              continue;
              }
           num_zeros++;
           if(num_zeros<=k)
              {
              current++;
              mx = max(mx,r+1-l);
              continue;
              }
           while (num_zeros > k)
              {
              if (nums[l] == 0)
                 {
                 num_zeros--;
                 
                
                 }
              current--;
              l++;
              mx = max(mx, r+1-l);
              }
           }
        return mx;

    }
};
int main()
{
   vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
   int k = 3;
   Solution sol;
   cout<<sol.longestOnes(nums,k);
   
   cout<<endl;
   return 0;
}