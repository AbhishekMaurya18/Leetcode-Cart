class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> t(n,vector<int> (n,-1));
        return mcm(nums,1,n-1,t);
        
    }
    
    int mcm(vector<int> &nums,int i,int j,vector<vector<int>>&t){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mx=0;
        for(int k=i;k<j;k++){
            int temp_ans=mcm(nums,i,k,t)+mcm(nums,k+1,j,t)+nums[i-1]*nums[k]*nums[j];
            mx=max(mx,temp_ans);
        }
        return t[i][j]=mx;
    }
};