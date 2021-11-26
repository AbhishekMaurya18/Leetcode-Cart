class Solution {
public:
    vector<vector<int>> t;
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        t= vector<vector<int>>(n,vector<int> (n,-1));
        return mcm(nums,1,n-1);
        
    }
    
    int mcm(vector<int> &nums,int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mx=0;
        for(int k=i;k<j;k++){
            int temp_ans=mcm(nums,i,k)+mcm(nums,k+1,j)+nums[i-1]*nums[k]*nums[j];
            mx=max(mx,temp_ans);
        }
        return t[i][j]=mx;
    }
};