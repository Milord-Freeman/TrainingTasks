
// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string& s, string& t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (auto sIt = s.begin(), tIt = t.begin(); tIt != t.end(); sIt++, tIt++){
            if (*tIt != *sIt) return *tIt;
        }
        return t.at(t.length());        
    }
};
