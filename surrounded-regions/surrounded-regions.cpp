class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        
        if(n<3 || m<3){
            return;
        }
        
        for(int i=0;i<n;i+=n-1){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j+=m-1){
                if(board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
                // cout<<board[i][j]<<"\n";
            }
        }
        return ;
    }
    
    void dfs(vector<vector<char>>&b, int i, int j){
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]!='O'){
            return ;
        }
        if(b[i][j]=='O'){
            //cout<<b[i][j]<<"\n";
            b[i][j]='1';
            dfs(b,i+1,j);
            dfs(b,i-1,j);
            dfs(b,i,j+1);
            dfs(b,i,j-1);
        }
        return;
    }
};