#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<numeric>
#include<stack>
#include<regex>
#include<sstream>
#include <queue>
#include <list>
#include <deque>
using namespace std;
struct TreeNode
   {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr)
      {
      }
   TreeNode(int x) : val(x), left(nullptr), right(nullptr)
      {
      }
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
      {
      }
   };
struct ListNode
   {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr)
      {
      }
   ListNode(int x) : val(x), next(nullptr)
      {
      }
   ListNode(int x, ListNode* next) : val(x), next(next)
      {
      }
   };

class Solution
   {
   public:
      int maxDepth(TreeNode* root)
         {
         if(!root)
            return 0;
         int ret = 0;
         return 1+max(maxDepth(root->left), maxDepth(root->right));
         }
   };
ListNode* MakeList(std::vector<int>& vec)
   {
   ListNode* head = nullptr;
   head = new ListNode(vec[0]);
   auto current = head;
   for (int i = 1;i < vec.size();i++)
      {
      auto next = new ListNode(vec[i]);
      current->next = next;
      current = current->next;
      }
   return head;
   }
void PrintList(ListNode* head)
   {
   auto current = head;
   while (current)
      {
      cout << current->val << ' ';
      current = current->next;
      }
   cout << endl;
   }
int main()
   {
   string s = "RD";
   Solution sol;
   std::vector<int>v{ 1,1000 };
   auto head = MakeList(v);

   auto ret = sol.pairSum(head);
   //PrintList(ret);
   cout << ret << endl;
   return 0;
   }