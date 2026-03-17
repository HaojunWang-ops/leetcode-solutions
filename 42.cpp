/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && height[i] > height[stk.top()])
        {
            int top = stk.top();
            stk.pop();
            if (stk.empty())
                break;
            int left = stk.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        stk.push(i);
    }
    return ans;     
    }
};
// @lc code=end
int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int result = sol.trap(height);
    cout << result << " ";
    return 0;
}
