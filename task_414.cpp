class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1 = nums[0], max2 = nums[0], max3 = nums[0], flag = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max1 && flag == -1) {
                max2 = max1;
                max1 = nums[i];
                max3 = max1;
                flag = 0;
            } else if (nums[i] < max1 && flag == -1) {
                max2 = nums[i];
                flag = 0;
            } else if (nums[i] > max1 && flag == 0) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
                flag = 1;
            } else if (nums[i] < max1 && nums[i] > max2 && flag == 0) {
                max3 = max2;
                max2 = nums[i];
                flag = 1;
            } else if (nums[i] < max2 && flag == 0) {
                max3 = nums[i];
                flag = 1;
            } else if (nums[i] > max1 && flag == 1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] < max1 && nums[i] > max2 && flag == 1) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] < max2 && nums[i] > max3 && flag == 1) {
                max3 = nums[i];
            }
        }
        return max3;
    }
};