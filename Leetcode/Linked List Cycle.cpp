class Solution {
public:
    bool hasCycle(ListNode *faster, ListNode* slower = nullptr) {
        if (!faster) // End reached
            return false;
        if (slower && faster == slower) // Found the same element twice: There's a LOOP
            return true;
        if (faster->next)
            return hasCycle(faster->next->next, slower ? slower->next : faster);
        return false; // Single element
    }
};
