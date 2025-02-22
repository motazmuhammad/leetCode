#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   bool canPlantFlower(vector<int>& flowerbed, int i)
      {
      int n = flowerbed.size();
      if(flowerbed.size()==0)
         return false;
      if(flowerbed.size() == 1)
         return flowerbed[0]==0;
      if(i<0|| i>=n)
         return false;
      if (i == 0)
         {
         return flowerbed[i] == 0 && flowerbed[i+1]==0;
         }
      if (i == n-1 &&i>0)
         {
         return flowerbed[i]==0&& flowerbed[i-1]==0;
         }
      return flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0;
      return false;
      }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       for (int i = 0;i < flowerbed.size();i++)
          {
          if (canPlantFlower(flowerbed, i))
             {
             n--;
             flowerbed[i] = 1;
             }
           }
       return n <=0;
    }
};
int main()
{
   vector<int> flowerbed{0};
   int n = 1;
   Solution sol;
   cout<<sol.canPlaceFlowers(flowerbed,n);
   return 0;
}