class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        int k1 = k % nums.size();
        for (int i = nums.size()-k1; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
        }
        for (int i = 0; i<nums.size()-k1; i++) {
            tmp.push_back(nums[i]);
        }
        if (k1!=0){
            nums = tmp;
        }
    }
};