
// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(const vector<int>& nums, const int goal) {

        int result = 0;
        int currentSum = 0;
        int zeroCount = 0;

        for (auto startIt = nums.begin(), currentIt = nums.begin();
             currentIt != nums.end(); currentIt++) {
            currentSum += *currentIt;

            while (startIt != currentIt &&
                   (*startIt == 0 || currentSum > goal)) {
                zeroCount = *startIt ? 0 : zeroCount + 1;
                currentSum -= *startIt;
                startIt++;
            }

            if (currentSum == goal) {
                result += 1 + zeroCount;
            }
        }

        return result;
    }
};
