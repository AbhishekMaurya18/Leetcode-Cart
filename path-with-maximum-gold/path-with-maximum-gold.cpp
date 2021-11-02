class Solution {
public:
    int n=0,m=0;
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(i,j,grid));
                }
            }
        }
        
        return ans;
    }
    int solve(int i, int j, vector<vector<int>>& grid){
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        
        int ans=0,in=grid[i][j];
        grid[i][j]=0;
        
        ans=max(ans,in+solve(i-1,j,grid));
        ans=max(ans,in+solve(i+1,j,grid));
        ans=max(ans,in+solve(i,j-1,grid));
        ans=max(ans,in+solve(i,j+1,grid));
        
        grid[i][j]=in;
        
        return ans;
    }
};