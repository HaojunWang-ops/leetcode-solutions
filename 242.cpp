/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lcpr-template-start
#include <iostream>
#include <vector>
#include <map>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
    int len1 = s.length();
    int len2 = t.length();
    if (len1 != len2)
    {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    bool result = sol.isAnagram(s, t);
    cout << result << " ";
    return 0;  
}

