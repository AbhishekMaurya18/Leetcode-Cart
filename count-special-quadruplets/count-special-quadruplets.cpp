class Solution {
public:
    int dp[51][5001][4];
    int solve(vector<int>& nums,int sum,int n,int k) {
        if(k==0 and sum==0) {
            return 1;
        }
        if(n<0 or k<0 or sum<0) {
            return 0;
        }
        if(dp[n][sum][k]!=-1) {
            return dp[n][sum][k];
        }
        return dp[n][sum][k]=(solve(nums,sum-nums[n],n-1,k-1)+solve(nums,sum,n-1,k));
    }
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=3;i<n;i++) {
            count+=solve(nums,nums[i],i-1,3);
        }
        return count;
    }
};