class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp;
        tmp.push_back(1);
        for (int i = 1; i<=rowIndex; i++) {
            tmp.push_back(1);
            for (int j = i-1; j>0; j--) {
                tmp[j] = tmp[j]+tmp[j-1];
            }
        }
        return tmp;
    }
};