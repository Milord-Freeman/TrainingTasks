
// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(const vector<int>& bills) {
        std::map<int, int> changes{{5, 0}, {10, 0}, {20, 0}};
        for (auto&& bill : bills) {
            switch (bill) {
            case 5:
                changes.at(5)++;
                break;
            case 10:
                if (changes.at(5)) {
                    changes.at(5)--;
                    changes.at(10)++;
                } else
                    return false;
                break;
            case 20:
                if (changes.at(10) && changes.at(5)) {
                    changes.at(10)--;
                    changes.at(5)--;
                    changes.at(20)++;
                } else if (changes.at(5) >= 3) {
                    changes.at(5) -= 3;
                    changes.at(20)++;
                } else
                    return false;
                break;
            }
        }
        return true;
    }
};
