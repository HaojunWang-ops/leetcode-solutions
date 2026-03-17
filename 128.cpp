/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s;
       if (nums.size() == 0)
            return 0; 
       for (int val : nums)
       {
            s.insert(val);
       }
       /*for (int val : s)
       {
            cout << val << endl;
       }
       cout << "***";*/
       int ans = 0;
       for (int val : s)
       {
            auto it = s.find(val - 1);
            if (it == s.end())
            {
                for (int i = 1; ; i++)
                {
                    auto nit = s.find(val + i);
                    if (nit != s.end())
                        ans = max(ans, i + 1);
                    else
                        break;
                }
                //cout << val << " " << ans << endl;
            }
       }
       if (ans == 0)
            return 1;
       return ans;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int result = sol.longestConsecutive(nums);
    cout << result << endl;
    return 0;
}
