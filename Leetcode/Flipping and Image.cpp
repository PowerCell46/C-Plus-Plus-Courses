class Solution {
    static void swapAndInvert(std::vector<int>::iterator& iter, std::vector<int>::reverse_iterator& reverse_iterator) {
        *iter ^= *reverse_iterator;
        *reverse_iterator ^= *iter;
        *iter ^= *reverse_iterator;

        *iter = *iter ? 0 : 1;
        *reverse_iterator = *reverse_iterator ? 0 : 1;
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto rowIter = image.begin(); rowIter != image.end(); ++rowIter) {
            auto colIterBegin = rowIter->begin();
            auto colIterReverseBegin = rowIter->rbegin();

            while (colIterBegin <= (colIterReverseBegin.base() - 1)) {
                if (colIterBegin == colIterReverseBegin.base() - 1)
                    *colIterBegin = *colIterBegin ? 0 : 1;
                else
                    swapAndInvert(colIterBegin, colIterReverseBegin);
                ++colIterBegin;
                ++colIterReverseBegin;
            }
        }
        return image;
    }
};
