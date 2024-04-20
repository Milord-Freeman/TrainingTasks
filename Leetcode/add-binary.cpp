
// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(std::string_view a, std::string_view b) {
        std::string result;
        auto& maxString = std::max(a, b);
        auto& minString = std::min(a, b);
        result.reserve(maxString.length() + 1);
        int buffer = 0;
        auto itMax = maxString.rbegin();
        auto itMin = minString.rbegin();

        bool end = false;
        while (!end) {

            int max = (itMax != maxString.rend()) ? *(itMax++) - '0' : 0;
            int min = (itMin != minString.rend()) ? *(itMin++) - '0' : 0;

            auto d = std::div(max + min + buffer, 2);
            result = std::to_string(d.rem) + result;
            buffer = d.quot;
            if ((itMax == maxString.rend()) && (itMin == minString.rend()) && !buffer)
                end = true;
        }

        return result;
    }
};
