class Solution {
public:
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 && node2) { // If both nodes are present
            if (node1->val != node2->val) // If the values are different 
                return false;

            bool leftResult = isSameTree(node1->left, node2->left); // Call with left child
            bool rightResult = isSameTree(node1->right, node2->right); // Call with right child

            return leftResult && rightResult;
        }
        if (node1 == nullptr && node2 || node1 && node2 == nullptr) // If one node is present and the other isn't
            return false;

        return true; // if both are nullptrs
    }
};
