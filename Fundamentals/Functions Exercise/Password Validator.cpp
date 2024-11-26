#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;


void validatePassword(const std::string&);

bool containsOnlyLettersAndDigits(const std::string&);

bool containsAtLeastTwoDigits(const std::string&);


int main() {
    std::string password;
    std::cin >> password;

    validatePassword(password);

    return 0;
}


void validatePassword(const std::string& password) {
    std::stringstream strStream{};

    if (password.length() < 6 || password.length() > 10)
        strStream << "Password must be between 6 and 10 characters" << std::endl;

    if (!containsOnlyLettersAndDigits(password))
        strStream << "Password must consist only of letters and digits" << std::endl;

    if (!containsAtLeastTwoDigits(password))
        strStream << "Password must have at least 2 digits" << std::endl;

    if (strStream.str().length() == 0)
        strStream << "Password is valid" << std::endl;

    std::cout << strStream.str();
}


bool containsOnlyLettersAndDigits(const std::string& text) {
    for (const char ch : text) {
        const char finalCh = std::tolower(ch);

        if (!((finalCh >= 'a' && finalCh <= 'z') || (ch >= '0' && ch <= '9')))
            return false;
    }

    return true;
}


bool containsAtLeastTwoDigits(const std::string& text) {
    int numOfDigits = 0;

    for (const char ch : text) {
        if (ch >= '0' && ch <= '9')
            numOfDigits++;
    }

    return numOfDigits >= 2;
}
