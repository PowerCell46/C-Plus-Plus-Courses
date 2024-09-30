#include <iostream>
using std::string;

string exclaim(string workingString);


int main() {

    string workingString = "To be, or not to be, that is the question:";

    string newWorkingString = exclaim(workingString);

    std::cout << newWorkingString;
    
    return 0;
}

string exclaim(string workingString) {
    for (int i = 0; i < workingString.length(); ++i) {
        if (workingString[i] == ',') workingString.replace(i, 1, "!");
    }
    return workingString;
}
