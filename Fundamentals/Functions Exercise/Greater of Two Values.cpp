#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


template<typename T>
T greaterOfTwo(const T& a, const T& b) {
    if (a > b)
        return a;
    return b;
}


int main() {
    std::string dataType;
    std::cin >> dataType;

    if (dataType == "int") {
        int a, b;
        std::cin >> a >> b;
        std::cout << greaterOfTwo(a, b) << std::endl;

    } else if (dataType == "char") {
        char a, b;
        std::cin >> a >> b;
        std::cout << greaterOfTwo(a, b) << std::endl;

    } else if (dataType == "string") {
        std::string a, b;
        std::cin >> a >> b;
        std::cout << greaterOfTwo(a, b) << std::endl;
    }

    // 77/100 in judge
    return 0;
}
