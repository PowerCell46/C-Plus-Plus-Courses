#include <complex>
#include <iostream>
#include <vector>
#include <sstream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* generateLinkList(const int* array, const int& arraySize, const int& currentIndex = 0) {
    if (currentIndex < arraySize) {
        ListNode* current = new ListNode{*(array + currentIndex), nullptr};

        ListNode* next = generateLinkList(array, arraySize, currentIndex + 1);
        current->next = next;

        return current;
    }

    return nullptr;
}

class Solution {
    int size{};
public:
    int getDecimalValue(ListNode* head, const int& currentIndex = 0) {
        if (head) {
            int sum = getDecimalValue(head->next, currentIndex + 1);

            if (head->val == 1)
                sum += std::pow(2, size - currentIndex - 1);

            return sum;
        }

        size = currentIndex;
        return 0;
    }
};

int main() {
    int arrSize = 1;
    int* array = new int[]{1};

    auto iter = generateLinkList(array, arrSize);
    Solution s;

    std::cout << s.getDecimalValue(iter);

    // iter = s.removeElements(iter, 7);

    // while (iter) {
    //     std::cout << iter->val << ' ';
    //     iter = iter->next;
    // }

    return 0;
}
