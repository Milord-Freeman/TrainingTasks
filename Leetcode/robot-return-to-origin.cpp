
// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string_view moves) {
        int x = 0, y = 0;
        for (auto&& move : moves) {
            switch (move) {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x++;
                break;
            case 'R':
                x--;
                break;
            }
        }
        return (x == 0) && (y == 0); 
    }
};
