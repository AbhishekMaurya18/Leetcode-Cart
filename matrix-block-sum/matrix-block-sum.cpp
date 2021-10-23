class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        int rangeSum [m + 1][n + 1];
        memset(rangeSum,0,sizeof(rangeSum));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + mat[i][j];
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int r1 = max(0, i - K), c1 = max(0, j - K), r2 = min(m, i + K + 1), c2 = min(n, j + K + 1);
                ans[i][j] = rangeSum[r2][c2] - rangeSum[r2][c1] - rangeSum[r1][c2] + rangeSum[r1][c1];
            }
        return ans;
    }
};
//rangeSum[i+1][j+1] =  rangeSum[i][j+1] + rangeSum[i+1][j]    -   rangeSum[i][j]   + mat[i][j]