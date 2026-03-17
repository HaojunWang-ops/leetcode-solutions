/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.length();
        int ans = 1e9;
        int lans = 0, rans = 0;
        unordered_map<char,int> mp;
        int left = 0,right = -1;
        int num = 0;
        int target = 0;
        for (char val : t)
        {
            if (mp[val] == 0)
            {
                target++;
            }
            mp[val]--;
        }
        while (left < len && right < len )
        {
            if (num < target)
            {
                if (right + 1 == len) break;
                right++;
                if (mp.find(s[right]) != mp.end())
                {
                    mp[s[right]]++;
                    if (mp[s[right]] == 0)
                    {
                        num++;
                    }
                }
            }
            else
            {
                if (right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    lans = left;
                    rans = right;
                }
                if (mp.find(s[left]) != mp.end())
                {
                    mp[s[left]]--;
                    if (mp[s[left]] == -1)
                    {
                        num--;
                    }
                }
                left++;
            }
            cout << left << " " << right << endl;
        }
        if (ans == 1e9)
            return "";
        return s.substr(lans, ans);
    }
};
// @lc code=end
int main()
{
    string s = "a";
    string t = "a";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << result << endl;
}
