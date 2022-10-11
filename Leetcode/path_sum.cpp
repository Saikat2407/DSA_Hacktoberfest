// https://leetcode.com/problems/path-sum/

class Solution {
public:
    static bool hasPathSum(TreeNode const* const root, const int sum) {
        if (root == nullptr)
            return false;
        if (sum == root->val && !root->left && !root->right)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};