class Solution {
    int maxFoundDepth{};
public:

    int maxDepth(TreeNode* root, int currentDepth = 0) {
        if (root) {
            ++currentDepth;
            maxFoundDepth = std::max(maxFoundDepth, currentDepth);

            maxDepth(root->left, currentDepth);
            maxDepth(root->right, currentDepth);

            return maxFoundDepth;
        }
        return maxFoundDepth;
    }
};
