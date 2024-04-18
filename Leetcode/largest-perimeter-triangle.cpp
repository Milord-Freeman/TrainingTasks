
// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.rbegin(), nums.rend());
        for (auto it = nums.begin(); it != nums.end() - 2; it++) {
            if (*it < (*(it + 1) + *(it + 2)))
                return *it + *(it + 1) + *(it + 2);
        }
        return 0;
    }
};
