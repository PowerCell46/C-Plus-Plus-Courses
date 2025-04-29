class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* previous = nullptr) {
        if (head) {
            ListNode* newHead = reverseList(head->next, head);
            head->next = previous;

            return newHead;
        }

        return previous;
    }
};
