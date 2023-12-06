class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int nums_max = nums[0], nums_sec_max = nums[0], ind = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums_max) {
                nums_sec_max = nums_max;
                nums_max = nums[i];
                ind = i;
            } else if (nums_max == nums_sec_max) {
                nums_sec_max = nums[i];
            } else if (nums_sec_max < nums[i]) {
                nums_sec_max = nums[i];
            }
        }
        if (nums_sec_max * 2 <= nums_max) {
            return ind;
        } else {
            return -1;
        }
    }
};