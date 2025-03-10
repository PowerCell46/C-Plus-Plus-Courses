#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
    void shiftVectorWithNumber(std::vector<int>& numbersVector, const std::vector<int>::iterator iter, const int& addElement) {
        for (auto currentIter = numbersVector.end() - 1; currentIter != iter; --currentIter)
            *currentIter = *(currentIter - 1);
        *iter = addElement;
    }

    void transferLeftOutElements(std::vector<int>& nums1, std::vector<int>::iterator iter, const std::vector<int>& nums2, int nums2Index) {
        while (iter != nums1.end()) {
            *iter = nums2.at(nums2Index++);
            ++iter;
        }
    }
    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1Moves = 0;
        int nums1Index = 0;
        int nums2Index = 0;
        auto iter = nums1.begin();

        while (iter < nums1.end() && nums2Index < n) {
            if (nums1Moves == m) {
                transferLeftOutElements(nums1, iter, nums2, nums2Index);
                break;
            }
            const int nums1Element = nums1.at(nums1Index);
            const int nums2Element = nums2.at(nums2Index);

            if (nums1Element > nums2Element) {
                shiftVectorWithNumber(nums1, iter, nums2Element);
                ++nums2Index;
                ++nums1Index;
                
            } else {
                ++nums1Index;
                ++nums1Moves;
            }
            
            ++iter;
        }
    }
};


int main() {
    Solution s;

    // std::vector<int> nums1{1,2,3,0,0,0};
    // std::vector<int> nums2{2,5,6};
    //
    // s.merge(nums1, 3, nums2, 3);


    // std::vector<int> nums1{1};
    // std::vector<int> nums2{};
    //
    // s.merge(nums1, 1, nums2, 0);


    // std::vector<int> nums1{0};
    // std::vector<int> nums2{1};
    //
    // s.merge(nums1, 0, nums2, 1);


    std::vector<int> nums1{4,5,6,0,0,0};
    std::vector<int> nums2{1,2,3};

    s.merge(nums1, 3, nums2, 3);


    for (int& num : nums1)
        std::cout << num << ' ';

    return 0;
}
