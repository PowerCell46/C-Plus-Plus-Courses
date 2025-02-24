#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const auto rowsIteratorBegin = img.begin();
        const auto rowsIteratorEnd = img.end();

        std::vector<std::vector<int>> resultMatrix;
        resultMatrix.resize(rowsIteratorEnd - rowsIteratorBegin); // Setting number of rows for the result matrix
        for (auto& row : resultMatrix) // Setting number of columns for the result matrix
            row.resize(rowsIteratorBegin->end() - rowsIteratorBegin->begin());

        auto resultRowIterator = resultMatrix.begin();

        for (auto rowIterator = rowsIteratorBegin; rowIterator != rowsIteratorEnd; ++rowIterator) {
            // std::vector<int> currentRow = *rowIterator; // CREATES A COPY, NOT WITH THE img ROW ITSELF!!!
            // const int rowIndex = rowIterator - rowsIteratorBegin;

            const auto currentRowIteratorBegin = rowIterator->begin();
            const auto currentRowIteratorEnd = rowIterator->end();

            auto resultColIterator = resultRowIterator->begin();

            for (auto colIterator = currentRowIteratorBegin; colIterator != currentRowIteratorEnd; ++colIterator) {
                int numberOfCells = 0, sumOfCells = 0;
                const int columnIndex = colIterator - currentRowIteratorBegin;

                const bool hasElementToTheLeft = colIterator != currentRowIteratorBegin;
                const bool hasElementToTheRight = (colIterator + 1) != currentRowIteratorEnd;
                const bool hasPreviousRow = rowIterator != rowsIteratorBegin;
                const bool hasNextRow = (rowIterator + 1) != rowsIteratorEnd;

                numberOfCells++; // Current Element
                sumOfCells += *colIterator;
                if (hasElementToTheLeft) { // <-
                    numberOfCells++;
                    sumOfCells += *(colIterator - 1);
                }
                if (hasElementToTheRight) { // ->
                    numberOfCells++;
                    sumOfCells += *(colIterator + 1);
                }

                if (hasPreviousRow) { // There's a previous row
                    numberOfCells++; // |
                    sumOfCells += (rowIterator - 1)->at(columnIndex);

                    if (hasElementToTheLeft) {
                        numberOfCells++; // |<-
                        sumOfCells += (rowIterator - 1)->at(columnIndex - 1);
                    }
                    if (hasElementToTheRight) {
                        numberOfCells++; // |->
                        sumOfCells += (rowIterator - 1)->at(columnIndex + 1);
                    }
                }

                if (hasNextRow) { // There's a next row
                    numberOfCells++; // |
                    sumOfCells += (rowIterator + 1)->at(columnIndex);

                    if (hasElementToTheLeft) {
                        numberOfCells++; // |<-
                        sumOfCells += (rowIterator + 1)->at(columnIndex - 1);
                    }
                    if (hasElementToTheRight) {
                        numberOfCells++; // |->
                        sumOfCells += (rowIterator + 1)->at(columnIndex + 1);
                    }
                }

                *resultColIterator = sumOfCells / numberOfCells;
                ++resultColIterator;
            }
            ++resultRowIterator;
        }

        return resultMatrix;
    }
};


int main() {
    Solution s;

    // std::vector<std::vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
    std::vector<std::vector<int>> matrix{{100,200,100},{200,50,200},{100,200,100}};

    for (auto& image_smoother : s.imageSmoother(matrix)) {
        for (int& smoother : image_smoother)
            std::cout << smoother << ' ';
        std::cout << '\n';
    }

    return 0;
}
