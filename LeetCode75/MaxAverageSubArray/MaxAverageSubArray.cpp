#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<long long> ps(nums.size());
        if(k-1>=nums.size()) return 0;
        partial_sum(nums.begin(), nums.end(),ps.begin());
        long long mx = ps[k-1];
        for (int i = k;i < nums.size();i++)
           {
           mx = max(mx, ps[i]-ps[i-k]);
           }
        return (double)mx/(double(k));
    }
};
int main()
{
   vector<int> nums{1,12,-5,-6,50,3 };
   int k = 4;
   Solution sol;
   cout<<sol.findMaxAverage(nums,k);
   
   cout<<endl;
   return 0;
}