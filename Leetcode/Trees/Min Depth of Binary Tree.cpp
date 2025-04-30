class Solution {
    int minFoundDepth{};
public:
    int minDepth(TreeNode* root, int currentDepth = 0) {
        if (root) {
            ++currentDepth;

            if (!root->left && !root->right) {
                if (minFoundDepth == 0)
                    minFoundDepth = currentDepth;
                else
                    minFoundDepth = std::min(minFoundDepth, currentDepth);
                
            } else {
                minDepth(root->left, currentDepth);
                minDepth(root->right, currentDepth);
            }
            
            return minFoundDepth;
        }

        return currentDepth;
    }
};
