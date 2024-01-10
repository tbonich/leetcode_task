class Solution {
public:
    string reverseWords(string s) {
        int st = 0, en = 0, n = s.size();
        string::iterator it = s.begin();
        while (it<s.end()) {
            while (*it != ' ' &&  it!=s.end()) {
                s[en] = *it;
                en++;
                it++;
            }
            if (st < en) {
                reverse(s.begin()+st, s.begin()+en);
                if (en!=n) {
                    s[en] = ' ';
                    en++;
                    st = en;
                } else {
                    it = s.end()-1;
                }
            }
            it++;
        }
        return s;
    }
};