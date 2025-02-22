class Solution {
public:
    bool isPalindrome(int x) {
        std::string strX = std::to_string(x);

        auto iter = strX.begin();
        auto rIter = strX.rbegin();

        while (iter != strX.end() && rIter != strX.rend()) {
            if (*iter != *rIter)
                return false;
            if (rIter.base() - 1 == iter)
                return true;

            ++iter;
            ++rIter;
        }

        return true;
    }
};
