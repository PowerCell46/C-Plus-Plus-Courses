#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using std::string;


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> charStack{};

        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            switch (*iter) {
                case '(':
                case '[':
                case '{': {
                    charStack.push(*iter);
                    break;
                }
                case ')': {
                    if (!charStack.empty()) {
                        if (charStack.top() == '(')
                            charStack.pop();
                        else
                            return false;
                    } else
                        return false;

                    break;
                }
                case ']': {
                    if (!charStack.empty()) {
                        if (charStack.top() == '[')
                            charStack.pop();
                        else
                            return false;
                    } else
                        return false;

                    break;
                }
                case '}': {
                    if (!charStack.empty()) {
                        if (charStack.top() == '{')
                            charStack.pop();
                        else
                            return false;
                    } else
                        return false;

                    break;
                }
            }
        }
        return charStack.empty();
    }
};


int main() {
    Solution s;

    std::cout << s.isValid(")");

    return 0;
}
