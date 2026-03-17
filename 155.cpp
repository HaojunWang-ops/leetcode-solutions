/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class MinStack {
public:
    stack<long long> diff_st;
    long long minx;
    MinStack() {
        
    } 
    
    void push(int val) {
        if (diff_st.empty())
        {
            diff_st.push(0);
            minx = val;
        }        
        else
        {
            long long diff = val - minx;
            diff_st.push(diff);
            if (diff < 0)
            {
                minx = val;
            }
        }
    }
    
    void pop() {
        long long diff = diff_st.top();
        if (diff < 0)
        {
            minx -= diff;
        }    
        diff_st.pop();
    }
    
    int top() {
        long long diff = diff_st.top();
        if (diff < 0)
        {
            return minx;
        }    
        else
            return minx + diff_st.top();
    }
    
    int getMin() {
        return minx;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
int main()
{
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(-1);
    st.push(0);
    cout << st.getMin() << endl;
    st.pop();
    st.pop();
    cout << st.getMin() << endl;
}
