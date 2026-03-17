/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 1)
            return 1;
        int l = -1, r = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (l < len - 1 && r < len - 1)
        {
            if (l > -1)
                mp[s[l]] = 0;
            l++;
            mp[s[l]] = 1;
            if (r < l)
                r = l;
            while (r < len - 1)
            {
                if (mp[s[r + 1]] == 0)
                {
                    r++;
                    mp[s[r]] = 1;
                }
                else
                {
                    break;
                }
            }
            ans  = max (ans, r - l + 1);
        }
    return ans; 
    } 
};
// @lc code=end
int main()
{
    string s = "au";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << result << " ";
    return 0;
}
