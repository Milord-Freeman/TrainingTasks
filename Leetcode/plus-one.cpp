
// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int buffer = 1;
        for (auto&& current = digits.rbegin(); current != digits.rend();
             current++) {
            auto div = std::div(*current + buffer, 10);
            *current = div.rem;
            buffer = div.quot;
        }
        if (buffer != 0) {
            digits.insert(digits.begin(), buffer);
        }

        return digits;
    }
};
