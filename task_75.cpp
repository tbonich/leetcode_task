class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index_min = 0;
        for (int i = 0; i<nums.size()-1; i++) {
            index_min = i;
            for (int j = i+1; j<nums.size(); j++) {
                if (nums[j]<nums[index_min]) {
                    index_min = j;
                }
            }
            swap(nums[i], nums[index_min]);
        }
    }
};