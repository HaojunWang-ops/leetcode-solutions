/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
       int n = s.length();
       string news;
       for (int i = 0; i < n; i++)
       {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                news += s[i] + ('a' - 'A');
            }
            else
                news += s[i];
        }
       }
       //cout << news << endl; 
       int l = 0;
       int r = news.length() - 1;
       while (l < r)
       {
        if (news[l] == news[r])
        {
            l++;
            r--;
            continue;
        }
        return false;
       }
       return true;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);
    cout << result << " ";
    return 0;
}
