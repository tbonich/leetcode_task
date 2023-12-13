class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int len_min = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].size()<len_min) {
                len_min = strs[i].size();
            }
        }
        int cnt = 0;
        while (cnt<len_min) {
            res.push_back(strs[0][cnt]);
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][cnt]!= res[cnt]) {
                    res.pop_back();
                    cnt = len_min;
                    break;
                }
            }
            cnt++;
        }
        return res;
    }
};