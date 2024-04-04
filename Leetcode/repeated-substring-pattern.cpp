
// https://leetcode.com/problems/repeated-substring-pattern

// There are two solutions. One is brute forced, the second 
// based on a trick with two strings. The main sense is if 
// a string contains a repeating pattern, then we can double 
// it and pop the first and the last char from the doubled string. 
// The string should contain our initial string.

// First one
class Solution {
public:
    bool repeatedSubstringPattern(string_view s) {

        return (std::string(s.begin() + 1, s.end()) +
                std::string(s.begin(), s.end() - 1))
                   .find(s) != std::string::npos;
    }
};

// Second one
class Solution {
public:
    bool repeatedSubstringPattern(string_view s) {
        for (auto charIt = s.begin(), midIt = std::next(s.begin(), s.length() / 2); charIt != midIt; charIt++) {
            if (m_bFindSubstringPatternRecursively(s.substr(0, std::distance(s.begin(), charIt) + 1), s))
                return true;
            else
                continue;
        }
        return false;
    }

private:
    bool m_bFindSubstringPatternRecursively(string_view sub, string_view s) {
        if (s.compare(sub) == 0)
            return true;
        else
            return s.starts_with(sub) ? m_bFindSubstringPatternRecursively(sub, s.substr(sub.length())) : false;
    }
};
