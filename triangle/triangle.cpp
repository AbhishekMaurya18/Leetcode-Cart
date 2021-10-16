class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n=tr.size();
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int op1=(j>0)?tr[i-1][j-1]+tr[i][j]:INT_MAX-1;
                int op2=(j<i)?tr[i-1][j]+tr[i][j]:INT_MAX-1;
                tr[i][j]=min(op1,op2);
            }
        }
        
        int ans=INT_MAX-1;
        for(int i=0;i<n;i++){
            ans=min(ans,tr[n-1][i]);
        }
        return ans;
    }
};