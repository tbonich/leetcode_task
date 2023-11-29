class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        int a, l;
        for (int i=0; i<nums.size(); i++) {
            l = 0;
            a = nums[i];
            while (a>0) {
                a = a/10;
                l++;
            }
            if (l%2==0) {
                res++;
            }
        }
        return res;
    }
};