/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int val = num1 + num2;
                st.push(val);
            }
            else if (tokens[i] == "-")
            {   
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int val = num2 - num1;
                st.push(val);
            }
            else if (tokens[i] == "*")
            {   
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int val = num1 * num2;
                st.push(val);
            }
            else if (tokens[i] == "/")
            {   
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int val = num2 / num1;
                st.push(val);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();        
    }
};
// @lc code=end
int main()
{
    vector<string> tokens = {"4","13","5","/","+"};
    Solution sol;
    int result = sol.evalRPN(tokens);
    cout << result << endl;
    return 0;
}
