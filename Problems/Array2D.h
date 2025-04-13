#ifndef LEETCODE_ARRAY2D_H
#define LEETCODE_ARRAY2D_H


#include <iostream>

class Array2D {
public:
    void print2DArray(int mat[][3], int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::pair<int, int> linearSearch(int mat[3][3], int rows, int cols, int target) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    int maxRowSum(int mat[][3], int rows, int cols) {
        int maxSum = INT_MIN;
        for (int i = 0; i < rows; ++i) {
            int sum = 0;
            for (int j = 0; j < cols; ++j) {
                sum += mat[i][j];
            }
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }

    int maxColumnSum(int mat[][3], int rows, int cols) {
        int maxSum = INT_MIN;
        for (int i = 0; i < cols; ++i) {
            int sum = 0;
            for (int j = 0; j < rows; ++j) {
                sum += mat[j][i];
            }
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }

    int diagonalSum(int mat[][3], int n) {
        //return sum of both the diagonals
        int sumOfDigitsInPrimaryDiagonal = 0;
        int sumOfDigitsInSecondaryDiagonal = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    sumOfDigitsInPrimaryDiagonal += mat[i][j];
                } else if ((i + j) == (n - 1)) {
                    sumOfDigitsInSecondaryDiagonal += mat[i][j];
                }
            }
        }

        return sumOfDigitsInPrimaryDiagonal + sumOfDigitsInSecondaryDiagonal;
    }

    std::pair<int, int> searchInSortedMatrix(std::vector<std::vector<int>>& mat, int target) {
        //O(log(m*n))
        int sRow = 0;
        int eRow = mat.size() - 1;
        while (sRow <= eRow) { // binary search on rows
            int midRow = sRow + (eRow-sRow)/2;
            int n = mat[midRow].size(); //mat[midRow].size() returns the size of that row.
            if (mat[midRow][0] <= target && target <= mat[midRow][n-1]) {
                int sCol = 0;
                int eCol = n-1;
                while (sCol <= eCol) { // binary search on columns
                    int midCol = sCol + (eCol-sCol)/2;
                    if (mat[midRow][midCol] == target) {
                        return {midRow, midCol};
                    } else if (mat[midRow][midCol] < target) {
                        sCol = midCol + 1;
                    } else {
                        eCol = midCol - 1;
                    }
                }
            } else if (target < mat[midRow][0]) {
                eRow = midRow - 1;
            } else {
                sRow = midRow + 1;
            }
        }

        return {-1, -1};
    }

    void solution() {
        int matrix[][3] = {{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
        int rows = 3;
        int cols = 3;

        std::cout << "2D Array:" << std::endl;
        print2DArray(matrix, rows, cols);

        std::pair<int, int> p = linearSearch(matrix, rows, cols, 8);
        std::cout << "Element found in 2D array at: " << p.first << "," << p.second << std::endl;

        std::cout << "Max Row Sum in 2D array: " << maxRowSum(matrix, rows, cols) << std::endl;
        std::cout << "Max Col Sum in 2D array: " << maxColumnSum(matrix, rows, cols) << std::endl;
        std::cout << "Diagonal sum in 2D array: " << diagonalSum(matrix, rows) << std::endl;
        std::vector<std::vector<int>> vec2D = {{1,2,3}, {4,5,6,7}, {8,9,10}};
        std::pair<int, int> p2 = searchInSortedMatrix(vec2D, 9);
        std::cout << "element found in sorted 2D vector at: " << p2.first << ", " << p2.second << std::endl;
    }
};


#endif //LEETCODE_ARRAY2D_H
