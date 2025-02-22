#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<unordered_map>;
#include<unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       unordered_map<int,queue<int> > num2index;
       for (int i = 0;i < nums.size();i++)
          {
          num2index[nums[i]].push(i);
           }
       int ret = 0;
       for (int i = 0;i < nums.size();i++)
          {
          int current = nums[i];
          while (num2index[current].size() && num2index[k - current].size())
             {
             num2index[current].pop();
             if(num2index[k-current].empty())
                break;
               
             num2index[k-current].pop();
             ret++;
             
             }
          }
       return ret;
    }
};
int main()
{
   vector<int> nums{6};
    int k = 6;
   Solution sol;
   cout<<sol.maxOperations(nums,k)<<endl;
   
   return 0;
}