
// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

// This is a classic path traversal problem. However, in the current version, 
// due to the limited nature of the grid, it can be solved with a simple set 
// of conditional statements. In reality, fields and paths are more complex.

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        const int rounds = moves.size();
        std::vector<std::vector<char>> grid(3, std::vector<char>(3));

        for (int i = 0; i < rounds; i++) {
            grid[moves[i][0]][moves[i][1]] = (i % 2) ? 'B' : 'A';
        }

        for (int i = 0; i < 3; i++) {
            if ((grid[i][0]) &&
                (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]))
                return string(1, grid[i][0]);
            if ((grid[0][i]) &&
                (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]))
                return string(1, grid[0][i]);
        }

        if (((grid[1][1]) &&
             (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])) ||
            ((grid[1][1]) &&
             (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])))
            return string(1, grid[1][1]);

        return (rounds == 9) ? "Draw" : "Pending";
    }
};
