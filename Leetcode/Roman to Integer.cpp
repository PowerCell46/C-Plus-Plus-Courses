#include <iostream>
#include <vector>
#include <sstream>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int number{};
        std::stringstream problematicNums;

        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            int currentNumber{};

            switch (*iter) {
                case 'M': {
                    currentNumber += 1'000;
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        currentNumber -= 100;
                        problematicNums.str("");
                    }
                    break;
                }
                case 'D': {
                    currentNumber += 500;
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        currentNumber -= 100;
                        problematicNums.str("");
                    }
                    break;
                }

                case 'C': {
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        std::stringstream resetStream{};

                        for (auto leftOutIter = leftOutNums.begin(); leftOutIter != leftOutNums.end(); ++leftOutIter) {
                            if (*leftOutIter == 'X') {
                                currentNumber -= 10;
                            } else {
                                resetStream << *leftOutIter;
                            }
                        }
                        problematicNums.str("");
                        problematicNums << resetStream.str();
                    }
                    problematicNums << 'C';
                    break;
                }
                case 'L': {
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        std::stringstream resetStream{};

                        for (auto leftOutIter = leftOutNums.begin(); leftOutIter != leftOutNums.end(); ++leftOutIter) {
                            if (*leftOutIter == 'X') {
                                currentNumber -= 10;
                            } else {
                                resetStream << *leftOutIter;
                            }
                        }
                        problematicNums.str("");
                        problematicNums << resetStream.str();
                    }
                    currentNumber += 50;
                    break;
                }

                case 'X': {
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        std::stringstream resetStream{};

                        for (auto leftOutIter = leftOutNums.begin(); leftOutIter != leftOutNums.end(); ++leftOutIter) {
                            if (*leftOutIter == 'I') {
                                currentNumber--;
                            } else {
                                resetStream << *leftOutIter;
                            }
                        }
                        problematicNums.str("");
                        problematicNums << resetStream.str();
                    }
                    problematicNums << 'X';
                    break;
                }
                case 'V': {
                    if (auto leftOutNums = problematicNums.str(); !leftOutNums.empty()) {
                        std::stringstream resetStream{};

                        for (auto leftOutIter = leftOutNums.begin(); leftOutIter != leftOutNums.end(); ++leftOutIter) {
                            if (*leftOutIter == 'I') {
                                currentNumber--;
                            } else {
                                resetStream << *leftOutIter;
                            }
                        }
                        problematicNums.str("");
                        problematicNums << resetStream.str();
                    }
                    currentNumber += 5;
                    break;
                }

                case 'I':
                    problematicNums << 'I';
                    break;
            }
            number += currentNumber;
        }

        std::string leftOutNumbers = problematicNums.str();
        for (auto iter = leftOutNumbers.begin(); iter != leftOutNumbers.end(); ++iter)
            switch (*iter) {
                case 'C': {
                    number += 100;
                    break;
                }
                case 'X': {
                    number += 10;
                    break;
                }
                case 'I': {
                    number++;
                    break;
                }
            }

        return number;
    }
};

int main() {
    Solution s;

    // std::cout << s.romanToInt("III");
    // std::cout << s.romanToInt("LVIII");
    // std::cout << s.romanToInt("MCMXCIV");
    std::cout << s.romanToInt("DCXXI");
    return 0;
}
