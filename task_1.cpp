class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i_res = 0;
        int j_res = 1;
        for (int i = 0; i<nums.size()-1; i++) {
            for (int j = i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j] == target) {
                    i_res = i;
                    j_res = j;
                    break;
                }
            }
            if (nums[i_res] + nums[j_res] == target) {
                break;
            }
        }
        vector<int> res = {i_res, j_res};
        return res;
    }
};