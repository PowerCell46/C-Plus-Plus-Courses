#include <iostream>
#include <queue>
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
    void postorder(TreeNode* node, std::vector<int>& resultVector) {
        if (node) {
            postorder(node->left, resultVector);
            postorder(node->right, resultVector);
            resultVector.push_back(node->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorder(root, result);

        return result;
    }
};

TreeNode* initializeTreeNode() {
    int rootValue;
    std::cout << "Enter root value: ";
    std::cin >> rootValue;

    if (rootValue != -1) {
        TreeNode* root = new TreeNode{rootValue, nullptr, nullptr};
        std::queue<TreeNode*> treeQueue;
        treeQueue.push(root);

        while (!treeQueue.empty()) {
            TreeNode* current = treeQueue.front();
            treeQueue.pop();

            int leftValue;
            std::cout << "Enter left value of " << current->val << ": ";
            std::cin >> leftValue;

            if (leftValue != -1) {
                current->left = new TreeNode{leftValue, nullptr, nullptr};
                treeQueue.push(current->left);
            }

            int rightValue;
            std::cout << "Enter right value of " << current->val << ": ";
            std::cin >> rightValue;

            if (rightValue != -1) {
                current->right = new TreeNode{rightValue, nullptr, nullptr};
                treeQueue.push(current->right);
            }
        }

        return root;
    }

    return nullptr;
}

int main() {
    int* array = new int[]{1, 2, 3};

    TreeNode* treeNode = initializeTreeNode();

    Solution s;
    auto v = s.postorderTraversal(treeNode);

    for (int i : v)
        std::cout << i << ' ';

    return 0;
}
