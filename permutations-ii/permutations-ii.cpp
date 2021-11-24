class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permute(nums,0);
        return ans;
    }
    void permute(vector<int>nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            //cout<<i<<" "<<start<<"\n";
            if(i==start or nums[start]!=nums[i]){
                swap(nums[start],nums[i]);
                permute(nums,start+1);
                //swap(nums[start],nums[i]);
            }
        }
    }
};