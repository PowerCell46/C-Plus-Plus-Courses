class Solution {
    void checkIfPalindrome(ListNode* listNode, std::stringstream& up, std::stringstream&down) {
        if (listNode) {
            up << listNode->val;
            checkIfPalindrome(listNode->next, up, down);
            down << listNode->val;
        }
    }

public:
    bool isPalindrome(ListNode* head) {
        std::stringstream up;
        std::stringstream down;

        checkIfPalindrome(head, up, down);

        return up.str() == down.str();
    }
};
