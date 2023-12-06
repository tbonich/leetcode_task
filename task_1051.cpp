class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;
        vector<int> arr(heights);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < heights.size() ; i++ ) {
            if (heights[i] != arr[i]) {
                res++;
            }
        }
        return res;
    }
};