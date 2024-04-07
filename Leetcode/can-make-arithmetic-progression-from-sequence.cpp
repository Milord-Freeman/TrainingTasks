
// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int delta = arr.at(1) - arr.at(0);
        for (auto first = arr.begin(), second = first + 1; second != arr.end(); first++, second++){
            if (*second - *first != delta)
            return false;
        }
        return true;
    }
};
