class Solution {
    void swap(char& a, char& b) {
        a ^= b;
        b ^= a ;
        a ^= b;
    }

public:
    void reverseString(vector<char>& s) {
        auto iter = s.begin();
        auto rIter = s.rbegin();

        for (int i = 0; i < s.size() / 2; i++) {
            swap(*iter, *rIter);
            ++iter;
            ++rIter;
        }

        for (char c : s)
            std::cout << c;
    }
};
