/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

 #include <iostream>
 #include <vector>
 #include <stack>
 using namespace std;
 // @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
       stack<int> st1;
       stack<int> st2;
       int answers[100005] = {0};
       for (int i = 0; i < n; i++)
       {
        if (st1.empty())
        {
            st1.push(temperatures[i]);
            st2.push(i);
        }
        else
        {
            while (!st1.empty() && st1.top() < temperatures[i])
            {
                int num = st2.top();
                answers[num] = i - num;
                st1.pop();
                st2.pop();
            }
            st1.push(temperatures[i]);
            st2.push(i);
        }
       }
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(answers[i]);
    }
    return result;     
    }
};
// @lc code=end
int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
