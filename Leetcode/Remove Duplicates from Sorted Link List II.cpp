class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int deleteValue = INT_MIN; // Int value keeping track of the value that has to be deleted

        while (head && head->next && head->next->val == head->val || head && head->val == deleteValue) {
            deleteValue = head->val;
            ListNode* temp = head->next;
            delete head;
            head = temp;
        } // If the first number is occurring mult times -> remove all of them

        ListNode* previous;
        ListNode* previousPrevious;
        ListNode* current = head;

        while (current) {
            if (current->val == deleteValue) { // Current value has to be deleted
                if (previousPrevious) {
                    ListNode* newCurrent = current->next;
                    previousPrevious->next = newCurrent;
                    delete current;
                    delete previous;
                    previous = previousPrevious;
                    current = newCurrent;
                    previousPrevious = nullptr;

                } else {
                    ListNode* newCurrent = current->next;
                    previous->next = newCurrent;
                    delete current;
                    current = newCurrent;
                }

            } else {
                deleteValue = current->val; // Update the delete value to current value
                previousPrevious = previous;
                previous = current;
                current = current->next;
            }
        }
        return head;
    }
};
