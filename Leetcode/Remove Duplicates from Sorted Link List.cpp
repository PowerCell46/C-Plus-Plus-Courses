class Solution {
public:
    ListNode* deleteDuplicates(ListNode* node, ListNode* first = nullptr) {
        if (node && node->next) {
            if (node->val == node->next->val) {
                ListNode* temp = node->next->next;
                delete node->next;
                node->next = temp;
                return deleteDuplicates(node, first ? first : node);
            }
            return deleteDuplicates(node->next, first ? first : node);
        }
        return first ? first : node;
    }
};
