class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        if(row==0)
            return -1;
        
        int col=grid[0].size();
        
        int days=0,fresh=0;
        queue<vector<int>> rot;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    rot.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        while(!rot.empty() && fresh>0){
            int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}},x,y,xx,yy;
            vector<int> cur;
            days++;
            
            int len=rot.size();
            
            while(len>0){
                len--;
                cur=rot.front();
                rot.pop();
                x=cur[0];
                y=cur[1];
                
                for(int i=0; i<4;i++){
                    xx=x+way[i][0];
                    yy=y+way[i][1];
                    
                    if(xx<0 || xx==row || yy<0 || yy==col || grid[xx][yy]==0 || grid[xx][yy]==2){
                        continue;
                    }
                    
                    fresh--;
                    grid[xx][yy]=2;
                    rot.push({xx,yy});
                    
                }
            }
        }
        
        if(fresh==0)
            return days;
        return -1;
    }
};