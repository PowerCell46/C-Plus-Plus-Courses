class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, const int& currentSum = 0) {
        if (root) {
            if (currentSum + root->val == targetSum && !root->left && !root->right)
                return true;

            bool leftResult = hasPathSum(root->left, targetSum, currentSum + root->val);
            bool rightResult = hasPathSum(root->right, targetSum, currentSum + root->val);

            return leftResult || rightResult;
        }

        return false;
    }
};
