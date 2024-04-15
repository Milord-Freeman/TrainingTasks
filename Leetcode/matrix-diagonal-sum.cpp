
// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int length = mat.size();
        int sum = 0;
        for (int i = 0; i < length; i++){
            sum += mat[i][i] + ((i != (length - 1) - i) ? mat[i][length-1 - i] : 0);
        }
        return sum;
    }
};
