class Solution {
public:
    int size{};
    ListNode* middleNode(ListNode* head, const int& currentIndex = 0) {
        if (head) {
            ListNode* res = middleNode(head->next, currentIndex + 1);

            if (size != 0 && size / 2 == currentIndex)
                return head;

            return res;
        }
        size = currentIndex;
        return nullptr;
    }
};
