/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int> > ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; first++)
        {
            if (first != 0 && nums[first] == nums[first - 1])
                continue;
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                while (second < third && nums[first] + nums[second] + nums[third] > 0)
                    third--;
                if (second == third)
                    break;
                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ans;
    }       
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> numbers = {-1,0,1,2,-1,-4};
    vector<vector<int> > result = sol.threeSum(numbers);
    for (auto val : result)
    {
        for (auto nval : val)
            cout << nval << " ";
        cout << endl;
    }
    return 0;
}