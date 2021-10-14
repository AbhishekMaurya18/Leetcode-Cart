class Solution {
public:
    int numSquares(int n) {
        if(n<4){
            return n;
        }
        vector<int> dp(n+1,INT_MAX-1);
        
        // for(int i=1;i<=sqrt(n);i++){
        //     sq[i]=i*i;
        // }
        
        dp[0]=0;
        for(int i=1;i<=n;i++){  //i means target at that point
            for(int j=1;j<=sqrt(n);j++){
                if(i<j*j){
                    break;
                }
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};