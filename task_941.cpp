class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag = -1;
        if (arr.size()<3) {
            return false;
        }
        for (int i=1; i< arr.size(); i++) {
            if (arr[i-1]==arr[i]) {
                return false;
            } else if ((arr[i-1] < arr[i]) && (flag == -1)) {
                flag = 0;
            } else if ((arr[i-1] > arr[i]) && (flag == 0)) {
                flag = 1;
            } else if ((arr[i-1] < arr[i]) && (flag == 1)) {
                return false;
            } else if ((arr[i-1] > arr[i]) && (flag == -1)) {
                return false;
            }
        }
        if (flag != 1) {
            return false;
        }
        return true;
    }
};