class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 || list2) {
            ListNode* current;
            ListNode* next;

            if (list1 && !list2 || (list1 && list2 && list1->val <= list2->val)) {
                current = new ListNode{list1->val, nullptr};
                 next = mergeTwoLists(list1->next, list2);

            } else if (list2 && !list1 || (list1 && list2 && list2->val < list1->val)) {
                current = new ListNode{list2->val, nullptr};
                next = mergeTwoLists(list1, list2->next);
            }

            current->next = next;

            return current;
        }

        return nullptr;
    }
};
