class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;

        vector<int> temp;

        while (srow <= erow && scol <= ecol) {

            // Top row
            for (int j = scol; j <= ecol; j++) {
                temp.push_back(matrix[srow][j]);
            }

            // Right column
            for (int i = srow + 1; i <= erow; i++) {
                temp.push_back(matrix[i][ecol]);
            }

            // Bottom row
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    temp.push_back(matrix[erow][j]);
                }
            }

            // Left column
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    temp.push_back(matrix[i][scol]);
                }
            }

            // Shrink boundaries
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return temp;
    }
};