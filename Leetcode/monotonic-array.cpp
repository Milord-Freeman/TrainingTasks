
// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncrease = true;
        bool isDecrease = true;
        int prev = nums.at(0);
        for (auto&& num : nums) {
            if (isIncrease || isDecrease) {
                if (num < prev)
                    isIncrease = false;
                if (num > prev)
                    isDecrease = false;
                prev = num;
            } else
                return false;
        }
        return isIncrease || isDecrease;
    }
};
