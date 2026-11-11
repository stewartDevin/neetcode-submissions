class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) continue; 

            if (l != r) {
                // swap l r values 
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
            }
            l++;
        }
    }
};