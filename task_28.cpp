class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1, j = 0, ind = -1;
        bool flag = false;
        if (haystack.size()<needle.size()) {
            return res;
        }
        for (int i = 0; i<haystack.size()-needle.size()+1; i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                res = i;
                break;
            }
        }
        return res;
    }
};