
// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = true; // True = positive number; twos compliment = 0, num > 0; False = negative number, etc;
        for (auto&& num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                sign = !sign;
        }
        return sign ? 1 : -1 ;
    }
};
