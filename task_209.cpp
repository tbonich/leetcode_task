class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 0;
        int ind = 0, s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            while (s >= target) {
                if (res == 0 || res > i + 1 - ind) {
                    res = i + 1 - ind;
                }
                s -= nums[ind];
                ind++;
            }
        }
        return res;
    }
};