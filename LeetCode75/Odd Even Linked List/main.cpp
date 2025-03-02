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
      ListNode* GetTail(ListNode* head)
         {
         if(head == nullptr|| head->next == nullptr)
            return head;
         ListNode* tail = nullptr;
         auto current = head;
         while(current)
            {
            tail = current;
            current = current->next;
            }
         return tail;
         }
      ListNode* oddEvenList(ListNode* head)
         {
         if(head == nullptr || head->next == nullptr)
            return head;
         auto current = head;
         int i = 3;
         auto odd_head = head;
         auto even_head = head->next;
         auto odd_current = odd_head;
         auto even_current = even_head;
         auto odd_tail = odd_head;
         current = current->next->next;

         while (current)
            {
            if (i % 2)
               {
               odd_tail = current;
               odd_current->next =current;
               odd_current = odd_current->next;
               }
            else
               {
               even_current->next = current;
               even_current = even_current->next;
               }
            current = current->next;
            i++;
            }
         even_current->next = nullptr;
            odd_tail->next = even_head;
         return odd_head;
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
   std::vector<int>v{ 1,2};
   auto head = MakeList(v);

   auto ret = sol.oddEvenList(head);
   PrintList(ret);
   cout << endl;
   return 0;
   }