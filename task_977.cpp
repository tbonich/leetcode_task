class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int l = 0;
        int r = nums.size()-1;
        while (r-l>0) {
            if (nums[r]*nums[r]>nums[l]*nums[l]){
                res.push_back(nums[r]*nums[r]);
                r--;
            } else {
                res.push_back(nums[l]*nums[l]);
                l++;
            }
        }
        res.push_back(nums[l]*nums[l]);
        reverse(res.begin(), res.end());
        return res;
    }
};