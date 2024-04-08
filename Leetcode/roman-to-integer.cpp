
// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(std::string_view roman) {
        const unordered_map<char, int> correspondence{
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        
        for (auto&& current = roman.begin(); current != roman.end(); current++) {
            if (current + 1 != roman.end() && correspondence.at(*current) < correspondence.at(*(current+1)))
                result -= correspondence.at(*current);        
            else
                result += correspondence.at(*current);            
        }
        
        // I know that such a noodle of switch cases and magic numbers is impossible to support, 
        // but this solution consumes the least memory and works the fastest, so I will leave it here for history.
  
        // for (auto&& current = roman.begin(); current != roman.end();) {
        //     switch (*current) {
        //     case 'I':
        //         if (*(current + 1) == 'V' or *(current + 1) == 'X')
        //             result -= 1;
        //         else
        //             result += 1;
        //         break;
        //     case 'V':
        //         result += 5;
        //         break;
        //     case 'X':
        //         if (*(current + 1) == 'L' or *(current + 1) == 'C')
        //             result -= 10;
        //         else
        //             result += 10;
        //         break;
        //     case 'L':
        //         result += 50;
        //         break;
        //     case 'C':
        //         if (*(current + 1) == 'D' or *(current + 1) == 'M')
        //             result -= 100;
        //         else
        //             result += 100;
        //         break;
        //     case 'D':
        //         result += 500;
        //         break;
        //     case 'M':
        //         result += 1000;
        //         break;
        //     }
        //     current++;
        // }

        return result;
    }
};
