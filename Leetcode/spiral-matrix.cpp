
// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxSize = matrix.size() * matrix.at(0).size();
        std::vector<int> result;
        result.reserve(maxSize);

        struct b {
            int left, right, up, down;
        };
        b border(0, matrix.at(0).size() - 1, 0, matrix.size() - 1);

        enum class direction { Right = 0, Down = 1, Left = 2, Up = 3 };
        using enum direction;
        direction move = Right;

        while (!((result.size() >= maxSize) || (border.left > border.right) && (border.up > border.down))) {
            std::cout << border.left << ", " << border.right << ", "
                      << border.up << ", " << border.down << " | ";
            switch (move) {
            case Right:
                std::cout << " Right ";
                for (int i = border.left; i <= border.right; i++) {
                    result.push_back(matrix[border.up][i]);
                }
                border.up++;
                move = Down;
                break;
            case Down:
                std::cout << " Down ";
                for (int i = border.up; i <= border.down; i++) {
                    result.push_back(matrix[i][border.right]);
                }
                border.right--;
                move = Left;
                break;
            case Left:
                std::cout << " Left ";
                for (int i = border.right; i >= border.left; i--) {
                    result.push_back(matrix[border.down][i]);
                }
                border.down--;
                move = Up;
                break;
            case Up:
                std::cout << " Up ";
                for (int i = border.down; i >= border.up; i--) {
                    result.push_back(matrix[i][border.left]);
                }
                border.left++;
                move = Right;
                break;
            }
        }

        return result;
    }
};
