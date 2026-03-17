/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start


/*class Solution
{
public:
    void reorderList(ListNode *head)
    {
       vector<ListNode*> v;
       ListNode *curr = head;
       while (curr != nullptr)
       {
        v.push_back(curr);
        curr = curr->next;
       } 

       curr = head;
       int i = 0, j = v.size() - 1;
       while (i < j)
       {
            v[i]->next = v[j];
            i++;

            if (i == j){
                break;
            }

            v[j]->next = v[i];
            j--;
       }
       v[j]->next = nullptr;
    }
};*/
class Solution
{
public:
    void reorderList (ListNode* head)
    {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        while (fast_ptr != nullptr && fast_ptr->next != nullptr){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        ListNode* curr = slow_ptr->next;
        slow_ptr->next = nullptr;

        ListNode* prev = nullptr;
        while (curr != nullptr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt; 
        }

        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2 != nullptr){
            ListNode* nxt1 = p1->next;
            ListNode* nxt2 = p2->next;

            p1->next = p2;
            p2->next = nxt1;

            p1 = nxt1;
            p2 = nxt2;
        }
    }
};
// @lc code=end
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode (4);
    curr = curr->next;
    Solution sol;
    sol.reorderList(head);
    curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
    return 0;
}