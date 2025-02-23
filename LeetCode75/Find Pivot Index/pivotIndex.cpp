#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> ps(nums.size()+2, 0);
        partial_sum(nums.begin(), nums.end(), ps.begin()+1);
        ps.back() = ps[ps.size()-2];
        for (int i = 1;i < ps.size()-1 ;i++)
           {
           int left = ps[i-1];
           int right = ps.back() - ps[i];
           if(left == right)
              return i-1;
           }
        return -1;
    }
};
int main()
{
   vector<int> nums{1,7,3,6,5,6};
   int k = 3;
   Solution sol;
   cout<<sol.pivotIndex(nums);
   
   cout<<endl;
   return 0;
}