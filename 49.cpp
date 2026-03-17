/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < n; i++)
        {
            string str = strs[i];
            string tmp = str;
            sort(str.begin(),str.end());
            m[str].push_back(tmp);
        }
        vector<vector<string> > ans;
        int cnt = 0;   
        for (auto& pair : m)
        {
         ans.push_back(pair.second);   
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string> > result;
    result = sol.groupAnagrams(strs);
    for (auto vals : result)
    {
        for (auto val : vals)
        {
            cout << val << " ";
        }
        cout << endl;
    } 
    return 0;
}
