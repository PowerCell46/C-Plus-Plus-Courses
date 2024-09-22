#include <iostream>

using std::string;

class URL {
private:
    string protocol, recourse;

public:
    URL(string urlProcotol, string urlRecourse) {
        protocol = urlProcotol;
        recourse = urlRecourse;
    }

    string getFullPath() {
        return protocol + "://" + recourse;
    }
};


int main() {
    string protocol, recourse;

    std::cout << "Enter a protocol: ";
    std::cin >> protocol;

    std::cout << "Enter a recourse: ";
    std::cin >> recourse;

    URL url = URL(protocol, recourse);

    std::cout << url.getFullPath();

    return 0;
}
