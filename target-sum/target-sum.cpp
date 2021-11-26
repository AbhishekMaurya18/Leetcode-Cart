class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(abs(target)>sum)
            return 0;
        
        int s=(sum+target);
        
        if(s%2!=0)
            return 0;
        
        return countSubsetSum(nums,s/2,n);
    }
    
    int countSubsetSum(vector<int>&nums,int s,int n){
        int t[n+1][s+1];
        t[0][0]=1;
        
        //initialize
        for(int j=1;j<=s;j++){
            t[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            if(nums[i-1]==0)
                t[i][0]=2*t[i-1][0]; //mul by 2 b/z we can include or exclude 0 in sum
            else
                t[i][0]=t[i-1][0];
        }
        
        //code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(nums[i-1]<=j){
                    t[i][j]=(t[i-1][j-nums[i-1]] + t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][s];
    }
};