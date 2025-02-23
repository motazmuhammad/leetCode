#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<unordered_set>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       set<int> s1(nums1.begin(), nums1.end());
       set<int> s2(nums2.begin(), nums2.end());
       std::vector<int> ret1;
       std::vector<int> ret2;
       set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(ret1));
       set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(ret2));
       return std::vector<std::vector<int>>{ret1, ret2};
    }
};
int main()
{
   vector<int> nums{1,7,3,6,5,6};
   int k = 3;
   Solution sol;
   cout<<sol.findDifference(nums,nums);
   
   cout<<endl;
   return 0;
}