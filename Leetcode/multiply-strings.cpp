
// https://leetcode.com/problems/multiply-strings

// !!! NOT COMPLETED !!!

class Solution {
public:
    string multiply(string_view num1, string_view num2) {
        auto& max = std::max(num1, num2);
        auto& min = std::min(num1, num2);
        std::vector<int> vecMax;
        vecMax.reserve(max.length());
        std::vector<int> vecMin;
        vecMin.reserve(min.length());
        for (auto it = max.begin(); it != max.end(); it++) {
            vecMax.push_back(*it - '0');
        }
        for (auto it = min.begin(); it != min.end(); it++) {
            vecMin.push_back(*it - '0');
        }

        for (auto num : vecMax) {
            std::cout << num;
        }
        std::cout << " x ";
        for (auto num : vecMin) {
            std::cout << num;
        }
        // std::cout << " = ";

        // int buffer = 0;
        std::vector<std::vector<int>> matrix(vecMin.size(),
                                             std::vector<int>(vecMax.size()));

        for (int minIndex = vecMin.size() - 1; minIndex >= 0; minIndex--) {
            int buffer = 0;
            for (int maxIndex = vecMax.size() - 1; maxIndex >= 0; maxIndex--) {
                auto d =
                    std::div(vecMax[maxIndex] * vecMin[minIndex] + buffer, 10);
                buffer = d.quot;
                matrix[vecMin.size() - 1 - minIndex][maxIndex] = d.rem;
            }
        }
        // hotfix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                matrix[i].push_back(0);
            }
        }
        // second hotfix
        for (int i = 0; i < matrix.size(); i++) {
            std::reverse(matrix[i].begin(),
                         matrix[i].end()); // God, forgive me.
        }

        // for (auto row : matrix) {
        //     for (auto col : row) {
        //         std::cout << col;
        //     }
        //     std::cout << " + ";
        // }

        std::vector<int> result;
        result.reserve(vecMax.size() + vecMin.size());
        int buffer = 0;

        for (int j = 0; j < matrix[matrix.size() - 1].size(); j++) {
            for (int i = 0; i < matrix.size(); i++) {
                if (j < matrix[i].size()) {
                    buffer += matrix[i][j];
                    // cout << j << " ";
                }
            }
            auto d = std::div(buffer, 10);
            result.push_back(d.rem);
            buffer = d.quot;
        }

        std::cout << " = ";
        for (auto i : result) {
            std::cout << i;
        }
        std::reverse(result.begin(), result.end());
        std::string res;
        for (int i : result) {
            res += std::to_string(i);
        }
        return res;
    }
};
