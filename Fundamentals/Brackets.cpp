#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int main() {
    const std::string VALID = "valid";
    const std::string INVALID = "invalid";

    std::vector<char> brackets;
    std::string inputLine, result;
    std::cin >> inputLine;

    for (const char &ch: inputLine) {
        switch (ch) {
            case '(':
                brackets.push_back(ch);
                break;

            case '[':
                if (brackets.size() > 0) {
                    if (brackets.at(brackets.size() - 1) == '(') {
                        std::cout << INVALID << std::endl;
                        return 0;
                    }
                }
                brackets.push_back(ch);
                break;

            case '{':
                if (brackets.size() > 0) {
                    if (brackets.at(brackets.size() - 1) == '(' || brackets.at(brackets.size() - 1) == '[') {
                        std::cout << INVALID << std::endl;
                        return 0;
                    }
                }
                brackets.push_back(ch);
                break;

            case ')':
                if (brackets.size() == 0) {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                if (brackets.at(brackets.size() - 1) == '(')
                    brackets.pop_back();
                else {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                break;

            case ']':
                if (brackets.size() == 0) {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                if (brackets.at(brackets.size() - 1) == '[')
                    brackets.pop_back();
                else {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                break;

            case '}':
                if (brackets.size() == 0) {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                if (brackets.at(brackets.size() - 1) == '{')
                    brackets.pop_back();
                else {
                    std::cout << INVALID << std::endl;
                    return 0;
                }
                break;
        }
    }

    std::cout << (brackets.size() == 0 ? VALID : INVALID) << std::endl;

    return 0;
}
