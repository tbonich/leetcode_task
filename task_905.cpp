class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int ind = 0, n = nums.size();
        int j = n - 1;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                res[ind] = nums[i];
                ind++;
            } else {
                res[j] = nums[i];
                j--;
            }
        }
        return res;
    }
};