class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res = -1, n = nums.size();
        int t = 0, sum = 0;
        for (int el : nums) {
            sum += el;
        }
        int l = 0, r = sum;
        while (t < n) {
            if (l == (r-nums[t])) {
                res = t;
                break;
            } else {
                l += nums[t];
                r -= nums[t];
            }
            t++;
        }
        return res;
    }
};