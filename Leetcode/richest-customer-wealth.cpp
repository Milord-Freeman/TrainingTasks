
// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich = 0;
        for (auto&& customer : accounts) {
            rich = std::max(
                rich, std::accumulate(customer.begin(), customer.end(), 0));
        }
        return rich;
    }
};
