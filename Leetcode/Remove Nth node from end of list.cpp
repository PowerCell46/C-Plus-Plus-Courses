#include <iostream>
#include <sstream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int currentReverseIndex = 0;
    ListNode* removeFromEnd(ListNode* node, const int& deleteIndex, ListNode* previous = nullptr, ListNode* first = nullptr) {
        if (node) {
            removeFromEnd(
                node->next,
                deleteIndex,
                node,
                first ? first : node
            );

            if (currentReverseIndex == deleteIndex) {
                if (previous) {
                    previous->next = node->next;
                    delete node;
                    ++currentReverseIndex;
                    return first;

                } else {
                    ListNode* newHead = node->next;
                    delete node;
                    ++currentReverseIndex;
                    return newHead;
                }
            }
            if (currentReverseIndex)
                ++currentReverseIndex;

            return first ? first : node;
        }
        
        ++currentReverseIndex;
        return first;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeFromEnd(head, n);
    }
};
