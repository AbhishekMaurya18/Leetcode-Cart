class Solution {
    int dp[1001][2][101];
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        for(int day=n-1; day>=0;day--){
            for(int trans=0;trans<=k;trans++){
                if(day==n-1){
                    dp[day][0][trans]=0; //do not own stock
                    dp[day][1][trans]=(trans>=1)?prices[day]:0;
                }
                else{
                    dp[day][0][trans]=max(-prices[day]+dp[day+1][1][trans],dp[day+1][0][trans]);
                    dp[day][1][trans]=max(((trans>=1)?prices[day]+dp[day+1][0][trans-1]:0),dp[day+1][1][trans]);
                }
            }
        }
        return dp[0][0][k];
    }
};