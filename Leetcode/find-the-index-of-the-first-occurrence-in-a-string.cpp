
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string_view haystack, string_view needle) {
        if (auto substring = haystack.find(needle); substring != std::string::npos){
            return substring;
        }
        return -1;
    }
};
