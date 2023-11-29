class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        res[0] = nums[0];
        for (int i=1; i<n; i++) {
            res[i] = res[i-1] + nums[i];
        }
         return res;
    }
};