class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1, ind = 0;
        for (int i = 1; i<nums.size(); i++) {
            if (nums[i]!=nums[ind]) {
                nums[ind + 1] = nums[i];
                ind++;
                res++;
            }
        }
        return res;
    }
};