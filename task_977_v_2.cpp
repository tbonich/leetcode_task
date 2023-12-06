class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int i = 0, j = n-1;
        int l = nums[i]*nums[i];
        int r = nums[j]*nums[j];
        for (int ind = n - 1; ind > 0; ind--) {
            if (l>r) {
                res[ind] = l;
                i++;
                l = nums[i]*nums[i];
            } else {
                res[ind] = r;
                j--;
                r = nums[j]*nums[j];
            }
        }
        res[0] = r;
        return res;
    }
};