class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        vector<string> vec_w;
        istringstream strm_s(s);
        while (strm_s >> tmp) {
            vec_w.push_back(tmp);
        }
        for (int i = vec_w.size() - 1; i>0; i--) {
            res += vec_w[i] + " ";
        }
        res += vec_w[0];
        return res;
    }
};