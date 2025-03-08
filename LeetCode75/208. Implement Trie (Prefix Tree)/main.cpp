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
#include <array>
using namespace std;
class Trie
   {
   struct Node
      {
      bool is_end_of_word;
      std::array<Node*, 26> children= {nullptr};
      Node():
         is_end_of_word(false)
         {

         }
      };
   Node* root;
   public:
      Trie()
         {
         root = new Node();
         }

      void insert(string word)
         {
         auto current = root;
         for (auto& c : word)
            {
            if (!current->children[c - 'a'])
               {
               current->children[c - 'a'] = new Node();
               }
            current = current->children[c - 'a'];

            }
         current->is_end_of_word = true;

         }

      bool search(string word, bool prefix = false)
         {
         auto current = root;
         for (auto& c : word)
            {
            if(!current->children[c-'a'])
               return false;
            current = current->children[c-'a'];
            }
         if(!prefix)
         return current->is_end_of_word;
         else
            return true;
         }

      bool startsWith(string prefix)
         {
         return search(prefix, true);
         }
   };
int main()
   {

   return 0;
   }