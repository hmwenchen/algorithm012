#include <vector>
#include <iostream>


class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;
        if (target < matrix[top][0] || target > matrix[bottom][n - 1]) {
            return false;
        }
        int foundRow = 0;
        while (top <= bottom) {
            int middle = top + (bottom - top) / 2;
            if (matrix[middle][0] == target) {
                return true;
            } else if (matrix[middle][0] < target) {
                if (matrix[middle][n - 1] >= target) {
                    foundRow = middle;
                    break;
                } else {
                    top = middle + 1;
                }
            } else {
                bottom = middle - 1;
            }
        }
        if (top > bottom) {
            foundRow = top;
        }
        // std::cout << "found row: " << foundRow << std::endl;
        int left = 0, right = n - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (matrix[foundRow][middle] == target) {
                return true;
            } else if (matrix[foundRow][middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }

    /**
     * [ref] https://leetcode.com/problems/search-a-2d-matrix/discuss/26226/C%2B%2B-12ms-O(log(mn))-no-library-functions-treat-matrix-as-an-array
     */
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int element = matrix[middle / n][middle % n];
            if (element == target) {
                return true;
            } else if (element < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    std::vector<std::vector<int> > matrix = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    // int target = 3;
    int target = 13;

    bool result = s.searchMatrix(matrix, target);
    std::cout << result << std::endl;
}