class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int amax = arr[arr.size() - 1];
        vector<int> res(arr.size(), -1);
        for (int i = arr.size() - 2; i>-1; i--) {
            res[i] = amax;
            if (arr[i]>amax) {
                amax = arr[i];
            }
        }
        return res;
    }
};