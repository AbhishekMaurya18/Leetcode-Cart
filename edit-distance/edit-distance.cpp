class Solution {
    int dp[501][501];
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,word1,word2);
    }
    
    int solve(int i, int j, string& s1, string& s2){
        if(i==s1.size() || j==s2.size()){
            return dp[i][j]=max(s2.size()-j,s1.size()-i);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i+1,j+1,s1,s2);
        }
        else{
            int op1=1+solve(i,j+1,s1,s2);//insert
            int op2=1+solve(i+1,j,s1,s2);//remove
            int op3=1+solve(i+1,j+1,s1,s2);//replace
            
            return dp[i][j]=min(op1,min(op2,op3));
        }
        //return dp[i][j];
    }
};