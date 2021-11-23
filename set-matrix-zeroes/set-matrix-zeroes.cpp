class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,col;
        int n=matrix.size(),m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(int i: row){
            for(int j=0;j<m;j++){
                matrix[i][j]=0;
            }
        }
        for(int j: col){
            for(int i=0;i<n;i++){
                matrix[i][j]=0;
            }
        }
        
        return ;
    }
};