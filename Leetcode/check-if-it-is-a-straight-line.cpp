
// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int N = coordinates.size();
        if (N == 2)
            return true;

        for (int i = 1; i < N - 1; i++) {
            int x1 = coordinates[i - 1][0], y1 = coordinates[i - 1][1];
            int x2 = coordinates[i][0],     y2 = coordinates[i][1];
            int x3 = coordinates[i + 1][0], y3 = coordinates[i + 1][1];

            if ((y3 - y2) * (x1 - x2) != (x3 - x2) * (y1 - y2))
                return false;
        }
        return true;
    }
};
