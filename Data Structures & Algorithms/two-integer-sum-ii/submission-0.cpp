class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seenNums;

        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];
            int complement = target - num;

            if (seenNums.find(complement) != seenNums.end()) {
                return {seenNums[complement] + 1, i + 1};
            }

            seenNums[num] = i;
        }

        return {};
    }
};
