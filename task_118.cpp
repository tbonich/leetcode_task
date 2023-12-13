class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int cnt = 0;
        vector<int> tmp;
        tmp.push_back(1);
        res.push_back(tmp);
        for (int i = 1; i<numRows; i++) {
            tmp.push_back(1);
            for (int j = i-1; j>0; j--) {
                tmp[j] = tmp[j]+tmp[j-1];
            }
            res.push_back(tmp);
        }
        return res;
    }
};