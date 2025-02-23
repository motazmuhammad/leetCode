#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
   bool CheckRowCol(vector<vector<int>>& grid, int row, int col)
      {
      for (int i = 0;i < grid.size();i++)
         {
         if(grid[row][i]!=grid[i][col])
            return false;
         }
      return true;
      }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ret = 0;
        for (int r = 0;r < n;r++)
           {
           for (int c = 0;c < n;c++)
              {
              ret+=CheckRowCol(grid,r,c);
              }
           }
        return ret;
    }
};
int main()
{
   vector<vector<int>> grid{{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2} };
   int k = 4;
   Solution sol;
   cout<<sol.equalPairs(grid);
   
   cout<<endl;
   return 0;
}