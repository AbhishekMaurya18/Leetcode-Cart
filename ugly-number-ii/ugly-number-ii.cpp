class Solution {
public:
    int nthUglyNumber(int n) {
        //code: system("CLS");//clear screen
        int i2=0,i3=0,i5=0;
        
        int dp[n],i=1;
       // memset(dp,0,sizeof dp);
        dp[0]=1;
        
        while(i<n){
            dp[i]=min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));
            
            if(dp[i]==dp[i2]*2)i2++;
            if(dp[i]==dp[i3]*3)i3++;
            if(dp[i]==dp[i5]*5)i5++;
            
            //cout<<dp[i]<<" ";
            i++;
        }
        return dp[n-1];
    }
};