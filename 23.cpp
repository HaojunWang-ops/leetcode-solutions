/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
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
struct CompareNode
{
    bool operator()(ListNode* a, ListNode* b){return a->val > b->val;}
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++){
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        if (pq.empty())
            return nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next != nullptr)
                pq.push(curr->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end

