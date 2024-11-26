#include <iostream>


std::string getDigitsNumberName(const std::string&);

std::string getTensNumberName(const std::string&);

std::string getHundredsNumberName(const std::string&);

std::string getThousandsNumberName(const std::string&);


int main() { // range [0, 9'999]
    std::string number;
    std::cin >> number;

    if (number.length() == 1) { // < 10
        std::cout << getDigitsNumberName(number) << std::endl;

    } else if (number.length() == 2) { // < 100
        std::cout << getTensNumberName(number) << std::endl;

    } else if (number.length() == 3) { // < 1'000
        std::cout << getHundredsNumberName(number) << std::endl;

    } else if (number.length() == 4) { // < 10'000
        std::cout << getThousandsNumberName(number) << std::endl;

    } else {
        std::cout << "Number is too big!" << std::endl;
    }

    // 90/100 in the Judge System
    return 0;
}


std::string getThousandsNumberName(const std::string& numberStr) {
    std::string thousands[] {
        "one", "two", "three",
        "four", "five", "six",
        "seven", "eight", "nine"
    };

    switch (numberStr.at(numberStr.length() - 4)) {
        case '0':
            return getHundredsNumberName(numberStr);

        case '1':
            return thousands[0] + " thousand " + getHundredsNumberName(numberStr);

        case '2':
            return thousands[1] + " thousand " + getHundredsNumberName(numberStr);

        case '3':
            return thousands[2] + " thousand " + getHundredsNumberName(numberStr);

        case '4':
            return thousands[3] + " thousand " + getHundredsNumberName(numberStr);

        case '5':
            return thousands[4] + " thousand " + getHundredsNumberName(numberStr);

        case '6':
            return thousands[5] + " thousand " + getHundredsNumberName(numberStr);

        case '7':
            return thousands[6] + " thousand " + getHundredsNumberName(numberStr);

        case '8':
            return thousands[7] + " thousand " + getHundredsNumberName(numberStr);

        default:
            return thousands[8] + " thousand " + getHundredsNumberName(numberStr);
    }
}


std::string getHundredsNumberName(const std::string& numberStr) {
    std::string hundreds[] {
        "one", "two", "three",
        "four", "five", "six",
        "seven", "eight", "nine"
    };

    switch (numberStr.at(numberStr.length() - 3)) {
        case '0':
            return getTensNumberName(numberStr);

        case '1':
            return hundreds[0] + " hundred " + getTensNumberName(numberStr);

        case '2':
            return hundreds[1] + " hundred " + getTensNumberName(numberStr);

        case '3':
            return hundreds[2] + " hundred " + getTensNumberName(numberStr);

        case '4':
            return hundreds[3] + " hundred " + getTensNumberName(numberStr);

        case '5':
            return hundreds[4] + " hundred " + getTensNumberName(numberStr);

        case '6':
            return hundreds[5] + " hundred " + getTensNumberName(numberStr);

        case '7':
            return hundreds[6] + " hundred " + getTensNumberName(numberStr);

        case '8':
            return hundreds[7] + " hundred " + getTensNumberName(numberStr);

        default:
            return hundreds[8] + " hundred " + getTensNumberName(numberStr);
    }
}


std::string getTensNumberName(const std::string& numberStr) {
    std::string tensOverTwenty[] {
        "ten", "twenty", "thirty",
        "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"
    };

    std::string tensBelowTwenty[] {
        "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen"
    };

    switch (numberStr.at(numberStr.length() - 2)) {
        case '0':
            return getDigitsNumberName(numberStr);

        case '1':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[0];

                case '1':
                    return tensBelowTwenty[0];

                case '2':
                    return tensBelowTwenty[1];

                case '3':
                    return tensBelowTwenty[2];

                case '4':
                    return tensBelowTwenty[3];

                case '5':
                    return tensBelowTwenty[4];

                case '6':
                    return tensBelowTwenty[5];

                case '7':
                    return tensBelowTwenty[6];

                case '8':
                    return tensBelowTwenty[7];

                default:
                    return tensBelowTwenty[8];
            }

        case '2':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[1];
                default:
                    return tensOverTwenty[1] + " " + getDigitsNumberName(numberStr);
            }

        case '3':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[2];
                default:
                    return tensOverTwenty[2] + " " + getDigitsNumberName(numberStr);
            }

        case '4':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[3];
                default:
                    return tensOverTwenty[3] + " " + getDigitsNumberName(numberStr);
            }

        case '5':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[4];
                default:
                    return tensOverTwenty[4] + " " + getDigitsNumberName(numberStr);
            }

        case '6':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[5];
                default:
                    return tensOverTwenty[5] + " " + getDigitsNumberName(numberStr);
            }

        case '7':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[6];
                default:
                    return tensOverTwenty[6] + " " + getDigitsNumberName(numberStr);
            }

        case '8':
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[7];
                default:
                    return tensOverTwenty[7] + " " + getDigitsNumberName(numberStr);
            }

        default:
            switch (numberStr.at(numberStr.length() - 1)) {
                case '0':
                    return tensOverTwenty[8];
                default:
                    return tensOverTwenty[8] + " " + getDigitsNumberName(numberStr);
            }
    }
}


std::string getDigitsNumberName(const std::string& numberStr) {
    std::string digits[] {
        "zero", "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
    };

    switch (numberStr.at(numberStr.length() - 1)) {
        case '0':
            return digits[0];

        case '1':
            return digits[1];

        case '2':
            return digits[2];

        case '3':
            return digits[3];

        case '4':
            return digits[4];

        case '5':
            return digits[5];

        case '6':
            return digits[6];

        case '7':
            return digits[7];

        case '8':
            return digits[8];

        default:
            return digits[9];
    }
}
