class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool duplicateFound = false;
        
        unordered_map<int, int> foundNums;
        for (int i = 0; i < nums.size(); i++) {
            foundNums[nums[i]]++;
            if (foundNums[nums[i]] >= 2) {
                duplicateFound = true;
                break;
            }
        }

        return duplicateFound;
    }
};