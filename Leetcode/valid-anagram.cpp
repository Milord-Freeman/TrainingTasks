
// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        std::cout << s << " " << t;
        return !s.compare(t);
    }
};
