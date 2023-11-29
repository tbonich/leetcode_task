class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        int cnt = 0;
        int n = arr.size();
        while (i<n) {
            if (arr[i]==0) {
                arr.insert(arr.begin()+i+1, 0);
                i = i + 2;
                cnt++;
            } else {
                i = i + 1;
            }
        }
        if (cnt!=0) {
            for (int j=cnt; j>0; j--) {
                arr.pop_back();
            }
        }
    }
};