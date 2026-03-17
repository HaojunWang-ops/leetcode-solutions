/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
             int top_num = st.top();
             int current_height = heights[top_num];
             st.pop();
             int weidth;
             if (st.empty())
             {
              weidth = i;  
             }
             else
             {
                weidth = i - st.top() - 1;
             }
             maxarea = max(maxarea, weidth * current_height);
            }   
            st.push(i);
        }
        return maxarea;
    }
};
// @lc code=end

int main()
{
    vector<int> heights = {2, 1, 2};
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << result << endl;
    return 0;
}
