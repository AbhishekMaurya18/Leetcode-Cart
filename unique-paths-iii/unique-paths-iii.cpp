class Solution {
public:
    int total = 0,n=0,m=0;  // total number of ways we have
    void dfs(vector<vector<int>>& grid,int i,int j,int count,int curr)
    {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==-1)
            return;
    
        if(grid[i][j]==2){
            if(count==curr){
                total++;
            }
        return;
        }
    
        grid[i][j] = -1;
    
        dfs(grid,i,j+1,count,curr+1);
        dfs(grid,i,j-1,count,curr+1);
        dfs(grid,i+1,j,count,curr+1);
        dfs(grid,i-1,j,count,curr+1);
    
        grid[i][j] = 0;
    
        return;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int x,y;

        int count = 0; // total number of empty squares we can walk over + one final destination

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    x = i;
                    y = j;
                }
                else if(grid[i][j]==0 or grid[i][j]==2)
                    count++;
                }
            }

        int curr = 0;   //currently how many empty squares we have passed
        dfs(grid,x,y,count,curr);
        return total;
    }
};