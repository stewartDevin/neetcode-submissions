class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevSums;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num; 

            if (prevSums.find(complement) != prevSums.end()) {
                return { prevSums[complement], i };
            }

            prevSums[num] = i;
        }
        return {};
    }
};
