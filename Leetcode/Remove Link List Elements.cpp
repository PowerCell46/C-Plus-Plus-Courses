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

// Iterative
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        ListNode* previous = nullptr;

        while (current) {
            if (current->val == val) {
                ListNode* temp = current->next;
                if (!previous)
                    head = temp;
                else
                    previous->next = temp;
                delete current;
                current = temp;

            } else {
                previous = current;
                current = current->next;
            }
        }

        return head;
    }
};

// Recursive
class Solution {
public:
    ListNode* removeElements(ListNode* current, int val, ListNode* previous = nullptr, ListNode* first = nullptr) {
        if (current) {
            if (current->val == val) {
                ListNode* nextNode = current->next;

                if (!previous)
                    first = nextNode;
                else
                    previous->next = nextNode;

                delete current;
                current = nextNode;
                return removeElements(current, val, previous, first);

            } else {
                return removeElements(current->next, val, current, first ? first : current);
            }
        }

        return first;
    }
};
