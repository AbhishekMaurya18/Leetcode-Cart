class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1,t=-nums[i];
            while(j<k){
                if(t>nums[j]+nums[k]){
                    j++;
                }
                else if(t<(nums[j]+nums[k])){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j<k && nums[j]==ans.back()[1]){
                        j++;
                    }
                    while(j<k && nums[k]==ans.back()[2]){
                        k--;
                    }
                }
                
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
            
        }
        return ans;
    }
};