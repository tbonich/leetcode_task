class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_pair;
        for (int i = 0; i<nums.size(); i++) {
            pair<int, int> p(nums[i], i);
            num_pair.push_back(p);
        }
        sort(num_pair.begin(), num_pair.end());
        int i = 0;
        int j = num_pair.size()-1;
        vector<int> res;
        while(num_pair[i].first + num_pair[j].first != target) {
            if (num_pair[i].first + num_pair[j].first > target) {
                j--;
            } else {
                i++;
            }
        }
        res.push_back(num_pair[i].second);
        res.push_back(num_pair[j].second);
        return res;
    }
};