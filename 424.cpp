/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int maxcount = 0;
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        while (right < len)
        {
            mp[s[right]]++;
            maxcount = max(maxcount, mp[s[right]]);
            if (right - left + 1> maxcount + k)
            {
                mp[s[left]]--;
                left++;
            }
            right++;
            //cout << left << " " << right << endl;
        }
        return right - left;
    }
};
// @lc code=end
int main()
{
    string s = "ABAB";
    int k = 2;
    Solution sol;
    int result = sol.characterReplacement(s, k);
    cout << result << endl;
}
