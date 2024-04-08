
// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string_view s) {
        int length = 0;
        for (auto current = s.rbegin(); current < s.rend(); current++) {
            if (*current == ' ')
                if (length == 0)
                    continue;
                else
                    break;
            length++;
        }
        return length;
    }
};
