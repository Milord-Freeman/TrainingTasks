
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

// But for the sake of history I’ll leave the classic solution with a stack

class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> st;
        for (auto&& ops : operations) {
            if (ops == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                st.push(second);
                st.push(first);
                st.push(first + second);
            } else if (ops == "D") {
                st.push(st.top() * 2);
            } else if (ops == "C") {                
                st.pop();
            } else {
                st.push(std::stoi(ops));
            };
        };

        int res = 0;
        while (!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    };
};
