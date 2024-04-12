
// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string_view instructions) {

        enum class dir { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };
        dir currentDir = dir::NORTH;
        std::pair<int, int> move =
            std::make_pair(0, 0); // first = x, secod = y;

        for (auto ins : instructions) {
            if (ins == 'G') {
                switch (currentDir) {
                case dir::NORTH:
                    move.second++;
                    break;
                case dir::SOUTH:
                    move.second--;
                    break;
                case dir::EAST:
                    move.first++;
                    break;
                case dir::WEST:
                    move.first--;
                    break;
                }
            } else if (ins == 'L') {
                int i = static_cast<int>(currentDir) - 1;
                if (i < 0)
                    i = 3;
                currentDir = static_cast<dir>(i);
            } else if (ins == 'R') {
                int i = static_cast<int>(currentDir) + 1;
                if (i > 3)
                    i = 0;
                currentDir = static_cast<dir>(i);
            }
        }

        return (move.first == 0 && move.second == 0) ? true
               : (currentDir != dir::NORTH)          ? true
                                                     : false;
    }
};
