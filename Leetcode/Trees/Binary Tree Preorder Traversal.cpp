#include <iostream>
#include <vector>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertInBinaryTree(TreeNode* node, const int& insertElement, TreeNode* first = nullptr) {
    if (node) {
        if (node->val > insertElement) {
            if (node->left)
                return insertInBinaryTree(node->left, insertElement, first ? first : node);
            node->left = new TreeNode{insertElement, nullptr, nullptr};
            return first ? first : node;

        } else {
            if (node->right)
                return insertInBinaryTree(node->right, insertElement, first ? first : node);
            node->right = new TreeNode{insertElement, nullptr, nullptr};
            return first ? first : node;
        }
    }
    return new TreeNode{insertElement, nullptr, nullptr};
}

TreeNode* generateBinaryTree(const int* array, const int& arraySize) {
    TreeNode* result = nullptr;

    for (int i = 0; i < arraySize; ++i)
        result = insertInBinaryTree(result, *(array + i));

    return result;
}

using std::vector;


class Solution {
    void preorder(TreeNode* node, std::vector<int>& resultVector) {
        if (node) {
            resultVector.push_back(node->val);
            preorder(node->left, resultVector);
            preorder(node->right, resultVector);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }
};

int main() {
    int* array = new int[]{1, 2, 3};

    TreeNode* treeNode = generateBinaryTree(array, 3);

    Solution s;

    auto v = s.preorderTraversal(treeNode);

        for (int i : v)
        std::cout << i << ' ';

    return 0;
}
