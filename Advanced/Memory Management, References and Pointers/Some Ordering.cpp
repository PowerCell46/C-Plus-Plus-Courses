#include <iostream>
#include <sstream>


std::string changeStringCasing(const std::string &str, char (*caseFunction)(const char &));

char changeCharToLowercase(const char &ch);

char changeCharToUppercase(const char &ch);


int main() {
    std::string str;
    std::getline(std::cin, str);

    std::cout
            << changeStringCasing(str, changeCharToLowercase) << '\n'
            << changeStringCasing(str, changeCharToUppercase);

    return 0;
}


std::string changeStringCasing(const std::string &str, char (*caseFunction)(const char &)) {
    std::stringstream resultStream{};

    for (const char &ch: str)
        resultStream << caseFunction(ch);

    return resultStream.str();
}


char changeCharToLowercase(const char &ch) {
    // if (ch >= 'A' && ch <= 'Z')
        return std::tolower(ch);
    // return ch;
}


char changeCharToUppercase(const char &ch) {
    // if (ch >= 'a' && ch <= 'z')
        return std::toupper(ch);
    // return ch;
}
