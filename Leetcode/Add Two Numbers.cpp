struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void reverseLinkNodeNum(ListNode* listNode, std::ostream& os) {
        if (listNode) {
            reverseLinkNodeNum(listNode->next, os);
            os << listNode->val;
        }
    }

    ListNode* createList(const std::string& str, const int& currentIndex = 0, ListNode* first = nullptr) {
        if (currentIndex < str.size()) {
            ListNode* currentNode = new ListNode{str.at(currentIndex) - '0'};
            ListNode* next = createList(str, currentIndex + 1, first ? first : currentNode);
            currentNode->next = next;

            return currentNode;
        }
        
        return nullptr;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        std::stringstream os;
        reverseLinkNodeNum(l1, os);
        std::string firstNumberStr = os.str();

        os.str("");
        reverseLinkNodeNum(l2, os);
        std::string secondNumberStr = os.str();

        int l1Index = firstNumberStr.size() - 1;
        int l2Index = secondNumberStr.size() - 1;

        std::stringstream resultStream{};
        int previous{};

        while (l1Index > -1 || l2Index > -1) {
            int l1Num = l1Index > -1 ? firstNumberStr.at(l1Index) - '0' : 0;
            int l2Num = l2Index > -1 ? secondNumberStr.at(l2Index) - '0' : 0;

            int currentResult = l1Num + l2Num + previous;
            previous = currentResult / 10;
            currentResult %= 10;

            resultStream << currentResult;

            --l1Index;
            --l2Index;
        }
        if (previous)
            resultStream << previous;

        std::string result = resultStream.str();
        // reverse(result.begin(), result.end());
        if (result.empty())
            result = "0";

        return createList(result);
    }
};
