/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int > m;
        int n = nums.size();
        for (int val : nums)
        {
            m[val]++;
            if (m[val] > 1)
                return true;   
        }
        return false;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    bool result = sol.containsDuplicate(nums);
    cout << result << endl;
    return 0;
}
