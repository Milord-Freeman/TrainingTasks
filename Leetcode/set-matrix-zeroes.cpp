
// https://leetcode.com/problems/set-matrix-zeroes

// In this task, the main emphasis is on saving space used. 
// A similar approach is possible when working in specific conditions, 
// for example when programming microcontrollers. Although, of course, 
// if you find me a controller with a 32-bit integer, but it doesn’t matter.
// Here is a normal solution with good readability and support.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::set<int> rows;
        std::set<int> columns;
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix.at(row).size(); col++) {
                if (matrix.at(row).at(col) == 0) {
                    rows.insert(row);
                    columns.insert(col);
                }
            }
        }

        for (auto& row : rows) {
            for (int i = 0; i < matrix.at(row).size(); i++) {
                matrix[row][i] = 0;
            }
        }
        for (auto& col : columns) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

// And here is the “correct solution” using a constant space.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroFirstCol = false;
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0)
                zeroFirstCol = true;
            for (int col = 1; col < matrix.at(row).size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix.at(0).size() - 1; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
            if (zeroFirstCol)
                matrix[row][0] = 0;
        }
    }
};

