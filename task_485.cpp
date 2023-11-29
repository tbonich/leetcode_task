class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i]==1) {
                sum++;
            } else {
                if (sum>res) {
                    res = sum;
                }
                sum = 0;
            }
            if (i==nums.size()-1) {
                if (sum>res) {
                    res = sum;
                }
            }
        }
        return res;
    }
};