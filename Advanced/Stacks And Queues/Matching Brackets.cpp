#include <iostream>
#include <sstream>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    for (int i = 0; i < expression.length(); ++i) {
        if (expression.at(i) == ')') {
            std::stringstream currentNestedExpression{};
            int reverseIndex = i, expressionsCounter = -1;

            while (true) {
                currentNestedExpression << expression.at(reverseIndex);
                if (expression.at(reverseIndex) == ')')
                    expressionsCounter++;

                if (expression.at(reverseIndex) == '(')
                    if (expressionsCounter > 0)
                        expressionsCounter--;
                    else
                        break;

                reverseIndex--;
            }

            std::string result = currentNestedExpression.str();
            std::reverse(result.begin(), result.end());
            std::cout <<  result << std::endl;
        }
    }

    return 0;
}

// 1 + (2 - (2 + 3) * 4 / (3 + 1)) * 5
// (2 + 3) - (2 + 3)
