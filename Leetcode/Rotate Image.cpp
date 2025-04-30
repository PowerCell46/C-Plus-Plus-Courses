class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::vector<std::vector<int>> resultMatrix(matrix.size(), std::vector<int>(matrix.size()));

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix.size(); ++j)
                resultMatrix[i][j] = matrix[matrix.size() - j - 1][i];

        matrix = std::move(resultMatrix);
    }
};
