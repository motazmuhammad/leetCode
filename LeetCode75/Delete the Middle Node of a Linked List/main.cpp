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
      int GetSize(ListNode* head)
         {
         int ret = 0;
         ListNode* current = head;
         while (current)
            {
            ret++;
            current = current->next;
            }
         return ret;
         }
      void DeleteNode(ListNode* node, ListNode*& head, ListNode* prev)
         {
         if (node == head)
            {
            head = head->next;
            delete node;
            head = nullptr;
            }
         if (prev == nullptr)
            return;
         prev->next = node->next;
         delete node;



         }
      ListNode* deleteMiddle(ListNode* head)
         {

         if (!head)
            return head;
         int sz = GetSize(head);
         if (sz <= 1)
            return nullptr;

         auto current = head;
         ListNode* prev = nullptr;
         ListNode* next = head->next;
         for (int i = 0;i < sz / 2;i++)
            {

            prev = current;
            current = current->next;
            }
         DeleteNode(current, head, prev);
         return head;
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
   std::vector<int>v{ 1 };
   auto head = MakeList(v);

   auto ret = sol.deleteMiddle(head);
   PrintList(ret);
   cout << endl;
   return 0;
   }