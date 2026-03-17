/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
       priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmp) > q(cmp);   
        for (int val : nums)
            mp[val]++;
        int i = 0;
        for (auto val : mp)
        {
            pair<int, int> p;
            p.first = val.first;
            p.second = val.second;
            if (i < k)
            {
                q.emplace(p);
                i++;
            }
            else
            {
                if (q.top().second < val.second)
                {
                    q.pop();
                    q.emplace(p);
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int val : result)
        cout << val << " ";
    return 0;
}
