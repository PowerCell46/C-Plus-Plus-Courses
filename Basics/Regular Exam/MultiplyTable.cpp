#include <iostream>

int main() {
    std::string numberStr;
    std::cin >> numberStr;
    int arr[3];

    for (int i = 0; i < 3; i++)
        arr[i] = numberStr.at(i) - 48;

    for (int i = 1; i <= arr[2]; ++i)
        for (int j = 1; j <= arr[1]; ++j)
            for (int p = 1; p <= arr[0]; ++p)
                std::cout << i << " * " << j << " * " << p << " = " << i * j * p << ';' << std::endl;

    return 0;
}
