
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        std::sort(salary.begin(), salary.end());
        double res;
        auto cout = salary.size();
        for (auto i = 1; i < cout - 1; i++) {
            res += salary.at(i);
        }
        return res / (cout - 2);
    }
};
