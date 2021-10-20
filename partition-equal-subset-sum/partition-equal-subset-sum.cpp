class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return false;
        }
        
        int sum=0;
        for(int i: nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        sum/=2;
        //cout<<sum;
        
        bool dp[n+1][sum+1];
        //memset(dp,0,sizeof dp);
        dp[0][0]=1;
        
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int x=1;x<=sum;x++){
                dp[i][x]=(x<nums[i-1]?0:dp[i-1][x-nums[i-1]])||dp[i-1][x];
                //cout<<dp[i][x]<<" ";
            }
            //cout<<"\n";
        }
        return dp[n][sum];
    }
};