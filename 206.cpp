/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <iostream>
#include <stdio.h>
using namespace std;
// @lc code=start

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *pre = nullptr;

        while (curr != nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        return pre;
    }
};*/
class Solution{
public:
    ListNode* reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *newNode = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newNode;
    }
};
// @lc code=end
int main()
{
    ListNode *fifth = new ListNode(5);
    ListNode *forth = new ListNode(4, fifth);
    ListNode *third = new ListNode(3, forth);
    ListNode *second = new ListNode(2, third);
    ListNode *head = new ListNode(1, second);
    
    Solution sol;

    ListNode *result = sol.reverseList(head);

    ListNode *curr = result;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
    return 0;
}
