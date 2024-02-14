class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> exp = heights;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i<exp.size()-1; i++) {
                if (exp[i]>exp[i+1]) {
                    swap(exp[i], exp[i+1]);
                    flag = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i<heights.size(); i++) {
            if (heights[i] != exp[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};