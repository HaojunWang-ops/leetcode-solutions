/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution
{
public:
    bool dfs(TreeNode *left, TreeNode *right){
        if (left == nullptr && right == nullptr){
            return true;
        }
        if (left == nullptr || right == nullptr){
            return false;
        }
        if (left->val != right->val){
            return false;
        }
        return (dfs(left->left, right->right) && dfs(left->right, right->left)); 
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr){
            return true;
        }        
        return dfs(root->left, root->right);
    }
};
// @lc code=end
