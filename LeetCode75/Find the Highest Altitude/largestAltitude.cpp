#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ps(gain.size()+1);
        ps[0] = 0;
        partial_sum(gain.begin(), gain.end(), ps.begin()+1);
        int mx = *max_element(ps.begin(), ps.end());
        return mx;
    }
};
int main()
{
   vector<int> gains{-4,-3,-2,-1,4,3,2};
   int k = 3;
   Solution sol;
   cout<<sol.largestAltitude(gains);
   
   cout<<endl;
   return 0;
}