
// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(std::string_view word1, std::string_view word2) {
        const int word1Length = word1.length();
        const int word2Length = word2.length();
        const int maxLenght = std::max(word1Length, word2Length);
        std::string result;
        result.reserve(2 * maxLenght);

        for (auto i = 0; i < maxLenght; i++) {
            if (i < word1Length)
                result.push_back(word1.at(i));

            if (i < word2Length)
                result.push_back(word2.at(i));
        }

        return result;
    };
};
