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
         if (head == nullptr || head->next == nullptr)
            return head;
         ListNode* tail = nullptr;
         auto current = head;
         while (current)
            {
            tail = current;
            current = current->next;
            }
         return tail;
         }
   ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current= next;
        }
        return prev;
    }
      int GetSize(ListNode* head)
         {
         auto current = head;
         int i = 0;
         while (current)
            {
            i++;
            current = current->next;
            }
         return i;
         }
      int pairSum(ListNode* head)
         {
         if (!head)
            return 0;
         if (!head->next)
            {
            return head->val;
            }
         int sz = GetSize(head);
         auto current = head;
         auto prev = head;
         prev = nullptr;
         for (int i = 0;i < sz / 2;i++)
            {
            prev = current;
            current = current->next;
            }
         auto next_head = current;
         prev->next = nullptr;
         auto rev = reverseList(next_head);
         current = head;
         auto current_rev = rev;
         int ret = 0;
         while (current)
            {
            ret=max(ret,current->val+current_rev->val);
            current= current->next;
            current_rev = current_rev ->next;

            }
         return ret;

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
   std::vector<int>v{ 1,1000};
   auto head = MakeList(v);

   auto ret = sol.pairSum(head);
   //PrintList(ret);
   cout << ret<<endl;
   return 0;
   }