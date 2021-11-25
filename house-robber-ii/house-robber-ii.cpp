class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()<=2){
            nums.insert(nums.begin(),0);
            return *max_element(nums.begin(),nums.end());
        }
        vector<int> num1(nums.begin()+1,nums.end());
        vector<int> num2(nums.begin(),nums.end()-1);
        return max(house(num1),house(num2));
        
    }
    int house(vector<int>&num){
        int n=num.size();
        int dp[n];
        dp[0]=num[0];
        //if (num[0]>num[1])dp[1]=num[0];
        //else dp[1]=num[1];
        dp[1]=max(num[0],num[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],(num[i]+dp[i-2]));
        }
        return max(dp[n-1],dp[n-2]);
    }
};