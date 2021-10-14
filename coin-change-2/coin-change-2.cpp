class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        //memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int sum=0;sum<=amount;sum++){
                if(sum==0){
                    dp[i][sum]=1;
                }
                else{
                    int op1= (coins[i-1]>sum) ? 0 : dp[i][sum-coins[i-1]];
                    int op2= (i==1) ? 0 : dp[i-1][sum];
                    dp[i][sum]=op1+op2;
                }
            }
        }
        return dp[n][amount];
    }
};