class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftPrevious;
        ListNode* leftCurrent;

        ListNode* rightPrevious;
        ListNode* rightCurrent;

        ListNode* previous = nullptr;
        ListNode* current = head;
        int currentIndex{};

        while (current) {
            ++currentIndex;

            if (currentIndex == k) {
                leftPrevious = previous;
                leftCurrent = current;
            }

            previous = current;
            current = current->next;
        }

        int reverseK = currentIndex - k + 1;

        current = head;
        previous = nullptr;
        currentIndex = 0;

        while (current) {
            ++currentIndex;

            if (currentIndex == reverseK) {
                rightPrevious = previous;
                rightCurrent = current;
                break;
            }

            previous = current;
            current = current->next;
        }

        if (leftCurrent == rightCurrent)
            return head;

        if (!leftPrevious) { // Swapping the head
            if (rightCurrent == leftCurrent->next) {
                rightCurrent->next = leftCurrent;
                leftCurrent->next = nullptr;
            } else {
                rightCurrent->next = leftCurrent->next;
                leftCurrent->next = nullptr;
                rightPrevious->next = leftCurrent;
            }

            return rightCurrent;
        }

        ListNode* temp = leftCurrent->next;

        if (leftCurrent->next == nullptr) {
            leftCurrent->next = rightCurrent->next && rightCurrent->next != leftCurrent ? rightCurrent->next : rightCurrent;
            if (leftPrevious)
                leftPrevious->next = rightCurrent;
            rightCurrent->next = nullptr;
            return leftCurrent;
        }

        if (leftCurrent != rightCurrent->next)
            leftCurrent->next = rightCurrent->next;
        else
            leftCurrent->next = rightCurrent;
        leftPrevious->next = rightCurrent;

        if (rightPrevious != leftCurrent)
            rightPrevious->next = leftCurrent;
        if (rightCurrent != temp) {
            rightCurrent->next = temp;

        } else {
            rightCurrent->next = leftCurrent;
        }
            return head;
    }
};
