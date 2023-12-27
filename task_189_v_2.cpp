class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int k1 = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k1);
        reverse(nums.begin()+k1, nums.end());
    }
};