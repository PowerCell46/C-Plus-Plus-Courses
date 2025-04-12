#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include "../Sort.h"


TEST_CASE("Sorts already sorted raw array") {
    constexpr size_t arrSize = 5;
    int* array = new int[arrSize]{1, 2, 3, 4, 5};
    const int* expected = new int[arrSize]{1, 2, 3, 4, 5};

    sort(array, arrSize);

    REQUIRE(std::memcmp(array, expected, arrSize * sizeof(int)) == 0);

    delete[] array;
    delete[] expected;
}


TEST_CASE("Sorts a reverse array") {
    constexpr size_t arrSize = 5;
    int* array = new int[arrSize]{5, 4, 3, 2, 1};
    const int* expected = new int[arrSize]{1, 2, 3, 4, 5};

    sort(array, arrSize);

    REQUIRE(std::memcmp(array, expected, arrSize * sizeof(int)) == 0);

    delete[] array;
    delete[] expected;
}


TEST_CASE("Sorts an array with duplicate elements") {
    constexpr size_t arrSize = 5;
    int* array = new int[arrSize]{2, 2, 1, 3, 3};
    const int* expected = new int[arrSize]{1, 2, 2, 3, 3};

    sort(array, arrSize);

    REQUIRE(std::memcmp(array, expected, arrSize * sizeof(int)) == 0);

    delete[] array;
    delete[] expected;
}


TEST_CASE("Sorts a single element array") {
    constexpr size_t arrSize = 1;
    int* array = new int[arrSize]{10};
    const int* expected = new int[arrSize]{10};

    sort(array, arrSize);

    REQUIRE(std::memcmp(array, expected, sizeof(int)) == 0);

    delete[] array;
    delete[] expected;
}


TEST_CASE("Sorts an empty array") {
    constexpr size_t arrSize = 0;
    int* array = new int[arrSize];
    const int* expected = new int[arrSize];

    sort(array, arrSize);

    REQUIRE(std::memcmp(array, expected, arrSize * sizeof(int)) == 0);

    delete[] array;
    delete[] expected;
}
