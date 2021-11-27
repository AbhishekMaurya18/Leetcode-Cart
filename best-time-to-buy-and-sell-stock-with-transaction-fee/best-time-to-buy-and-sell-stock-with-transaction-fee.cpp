class Solution {
public:
    int dp[50001][2];
    int maxProfit(vector<int>& prices,int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,fee,prices);
    }
    int solve(int i, bool own,int fee, vector<int>& prices){
        if(i==prices.size())
            return 0;
        
        if(dp[i][own]!=-1){
            return dp[i][own];
        }
        if(own){
            int op1=prices[i]+solve(i+1,0,fee,prices);
            int op2=solve(i+1,1,fee,prices);
            return dp[i][own]=max(op1,op2);
        }
        else{
            int op1=-(prices[i]+fee)+solve(i+1,1,fee,prices);
            int op2=solve(i+1,0,fee,prices);
            return dp[i][own]=max(op1,op2);
        }
    }
};