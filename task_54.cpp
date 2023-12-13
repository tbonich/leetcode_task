class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int cnt = 0, i = 0, j = 0;
        int flag = 1;
        int i_min = 0, i_max = m-1;
        int j_min = 0, j_max = n-1;
        vector<int> res(m*n, 0);
        while (cnt<n*m) {
            res[cnt] = matrix[i][j];
            cnt++;
            if (flag == 1) {
                j++;
                if (j == j_max+1) {
                    j--;
                    flag = 2;
                    i++;
                    i_min++;
                }
            } else if (flag == 2) {
                i++;
                if (i == i_max+1) {
                    i--;
                    flag = -1;
                    j--;
                    j_max--;
                }
            } else if (flag == -1) {
                j--;
                if (j == j_min-1) {
                    j++;
                    flag = -2;
                    i--;
                    i_max--;
                }
            } else if (flag == -2) {
                i--;
                if (i == i_min - 1) {
                    i++;
                    flag = 1;
                    j++;
                    j_min++;
                }
            }
        }
        return res;
    }
};