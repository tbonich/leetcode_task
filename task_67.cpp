class Solution {
public:
    string addBinary(string a, string b) {
        char c = '0';
        string res;
        int a_len = a.size(), b_len = b.size();
        while ((a_len>0) && (b_len>0)) {
            if (c == '1' && a[a_len-1] == '0' && b[b_len-1] == '0') {
                res.push_back('1');
                c = '0';
            } else if (c == '0' && a[a_len-1] == '1' && b[b_len-1] == '0') {
                res.push_back('1');
            } else if (c == '0' && a[a_len-1] == '0' && b[b_len-1] == '1') {
                res.push_back('1');
            } else if (c == '1' && a[a_len-1] == '1' && b[b_len-1] == '1') {
                res.push_back('1');
            } else if (c == '0' && a[a_len-1] == '0' && b[b_len-1] == '0') {
                res.push_back('0');
            } else {
                res.push_back('0');
                c = '1';
            }
            a_len--;
            b_len--;
        }
        while (a_len>0) {
            if (c == '1' && a[a_len-1]=='1') {
                res.push_back('0');
            } else if (c == '0' && a[a_len-1]=='0') {
                res.push_back('0');
            } else {
                res.push_back('1');
                c = '0';
            }
            a_len--;
        }
        while (b_len>0) {
            if (c == '1' && b[b_len-1]=='1') {
                res.push_back('0');
            } else if (c == '0' && b[b_len-1]=='0') {
                res.push_back('0');
            } else {
                res.push_back('1');
                c = '0';
            }
            b_len--;
        }
        if (c=='1') {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};