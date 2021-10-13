class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }
        
        int s=0;
        for(int i: nums){
            s+=i;
        }
        
        int ans1=kadane(nums,0,n-1,1);         //one interval
        int ans2=s+kadane(nums,1,n-1,-1);      //2-interval first element removed
        int ans3=s+kadane(nums,0,n-2,-1);      //2-interval last element removed
        
        return max(ans1,max(ans2,ans3));
        
    }
    
    int kadane(vector<int> &nums,int i,int j,int sign){
        
        int ans=INT_MIN,cur=INT_MIN;
        for(int k=i;k<=j;k++){
            cur=sign*nums[k]+max(cur,0);
            ans=max(ans,cur);
        }
        return ans;
    }
};