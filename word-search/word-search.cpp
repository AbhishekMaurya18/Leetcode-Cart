class Solution {
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size(),m=board[0].size();
        visited.resize(n,vector<bool>(m,false));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,int i, int j, string& word, int in){
        if(in==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]==true || board[i][j]!=word[in] ){
            return false;
        }
        
        visited[i][j]=true;
        if(dfs(board,i+1,j,word,in+1) || dfs(board,i-1,j,word,in+1) || dfs(board,i,j+1,word,in+1) || dfs(board,i,j-1,word,in+1)){
            return true;
        }
        visited[i][j]=false;
        return false;
    }
};