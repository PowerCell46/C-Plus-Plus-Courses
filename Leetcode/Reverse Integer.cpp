class Solution {
public:
    int reverse(int x) {
        std::stringstream reverseNumStream{};
        std::string xStr = std::to_string(x);
        auto rIter = xStr.rbegin();
        bool isNegative = false;

        while (true) {
            if (rIter == xStr.rend() - 1) {
                if (*rIter == '-')
                    isNegative = true;
                else
                    reverseNumStream << *rIter;
                break;
            }
            reverseNumStream << *rIter;
            ++rIter;
        }

        try {
            return std::stoi(reverseNumStream.str()) * (isNegative ? -1 : 1);

        } catch (std::out_of_range) {
            return 0;
        }
    }
};
