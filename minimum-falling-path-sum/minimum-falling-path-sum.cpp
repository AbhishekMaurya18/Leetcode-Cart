class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int op1=(j>0)?matrix[i][j]+matrix[i-1][j-1]:INT_MAX-1;
                int op2=matrix[i][j]+matrix[i-1][j];
                int op3=(j<n-1)?matrix[i][j]+matrix[i-1][j+1]:INT_MAX-1;
                matrix[i][j]=min(op1,min(op2,op3));
            }
        }
        
        int ans=INT_MAX-1;
        for(int i=0;i<n;i++){
            ans=min(ans,matrix[n-1][i]);
        }
        
        return ans;
//         return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};