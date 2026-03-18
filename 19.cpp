/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left_pointer = dummy;
        ListNode* right_pointer = dummy;
        int i = 0;
        while (i <= n){
            i++;
            right_pointer = right_pointer->next;
        }
        while (right_pointer != nullptr){
            right_pointer = right_pointer->next;
            left_pointer = left_pointer->next;
        }

        left_pointer->next = left_pointer->next->next;

        return dummy->next;
    }
};
// @lc code=end