class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs = "";
        int res = 0;
        for (auto i = 0; i<s.size(); i++) {
            subs = s[i];
            for (auto j = i+1; j<s.size(); j++) {
                if (subs.find(s[j]) != string::npos)
                    break;
                else
                    subs = subs + s[j];
            }
            int n = subs.size();
            res = max(res, n);
        }
        return res;
    }
};