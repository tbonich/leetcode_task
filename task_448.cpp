class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), ind = 0;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[nums[i]-1]++;
        }
        for (int i = 0; i < n; i++) {
            if (res[i] == 0) {
                res[ind] = i+1;
                ind++;
            }
        }
        for (int i = ind; i < n; i++) {
            res.pop_back();
        }
        return res;
    }
};