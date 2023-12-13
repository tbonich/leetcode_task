class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 1, j = 1, m = mat.size(), n = mat[0].size(); 
        vector<int> res(m*n, 0);
        bool flag = true;
        int ind = 0;
        while (i<=m && j<=n) {
            res[ind] = mat[i-1][j-1];
            ind++;
            if (flag) {
                i--;
                j++;
            } else {
                i++;
                j--;
            }
            if (i==0) {
                flag = false;
                i = 1;
                if (j>n) {
                    j--;
                    i++;
                }
            } 
            if (j==0) {
                flag = true;
                j = 1;
                if (i>m) {
                    i--;
                    j++;
                }
            }
            if (i>m) {
                flag = true;
                i = m;
                j = j+2;
            } else if (j>n) {
                flag = false;
                j = n;
                i = i+2;
            }
        }
        return res;
    }
};