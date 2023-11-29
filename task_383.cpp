class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        string s = "abcdefghijklmnopqrstuvwxyz";
        bool res = true;
        for (int i = 0; i<s.length();i++) {
            if (count(ransomNote.begin(), ransomNote.end(), s[i])>count(magazine.begin(), magazine.end(), s[i])) {
                res = false;
            }
        }
        return res;
    }
};