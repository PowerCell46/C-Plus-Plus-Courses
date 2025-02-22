class Solution {
public:
    int addDigits(int num) {
        std::string numStr = std::to_string(num);

        while (numStr.size() > 1) {
            int currentSum{};
            for (char& ch : numStr)
                currentSum += ch - 48;
            numStr = std::to_string(currentSum);
        }

        return std::stoi(numStr);
    }
};
