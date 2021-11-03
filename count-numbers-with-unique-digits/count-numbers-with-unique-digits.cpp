class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0){
            return 1;
        }
        int dp[n+1];
        memset(dp,0,sizeof dp);
        
        dp[1]=10;
        
        for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+permute(i); 
        }
        return dp[n];
    }
    int permute(int n){
        int ans=9,mul=9;
        while(n>1){
            ans*=mul;
            mul--;
            n--;
        }
        return ans;
    }
};