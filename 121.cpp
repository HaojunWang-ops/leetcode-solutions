/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = prices[0];
        for (int price : prices)
        {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};
// @lc code=end
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << result << " ";
    return 0;
}
