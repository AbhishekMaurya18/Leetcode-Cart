class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> line(102,0);
        
        for(int i: nums){
            ++line[i];
        }
        for(int i=1;i<102;i++){
            line[i]+=line[i-1];
        }
        vector<int> ans(nums.size(),0);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                ans[i]=line[nums[i]-1];
        }
        return ans;
    }
};