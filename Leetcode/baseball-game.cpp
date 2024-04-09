
// https://leetcode.com/problems/baseball-game

// This classic stack problem can be solved without using any additional space. 
// It is enough to simply modify the vector of strings that was passed to us by reference.
class Solution {
public:
    int calPoints(vector<string>& operations) {
        auto current = operations.begin();
        while (current != operations.end()) {
            if (*current == "+") {
                *current = std::to_string(std::stoi(*(current - 2)) + std::stoi(*(current - 1)));
                current++;
            } else if (*current == "D") {
                *current = std::to_string(std::stoi(*(current - 1)) * 2);
                current++;
            } else if (*current == "C") {                
                current = operations.erase(current - 1, current + 1);
            } else {
                current++;
            };
        };

        int res = 0;
        for (auto i : operations) {
            res += std::stoi(i);
        }

        return res;
    };
};
