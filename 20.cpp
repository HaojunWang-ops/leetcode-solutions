/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
       int n = s.length();
       if (n % 2 == 1) return false;
       stack<char> st;
       for (char val : s)
       {
        if (val == '(' || val == '{' || val == '[')
        {
            st.push(val);
        }
        if (val == ')')
        {
            if (st.empty()) return false;
            char c = st.top();
            if (c == '(')
                st.pop();
            else
                return false;
        }
        if (val == ']')
        {
            if (st.empty()) return false;
            char c = st.top();
            if (c == '[')
                st.pop();
            else
                return false;
        }
          if (val == '}')
        {
            if (st.empty()) return false;
            char c = st.top();
            if (c == '{')
                st.pop();
            else
                return false;
        }      
       }
       if (st.empty()) 
        return true;
       return false;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    string s = "([{)])";
    bool result = sol.isValid(s);
    cout << result << endl;
    return 0;
}
