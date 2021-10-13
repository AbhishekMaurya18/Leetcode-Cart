class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmin=nums[0],cmax=nums[0],res=nums[0];
        
        for(int j=1;j<nums.size();j++){
            int i=nums[j];
            int temp=cmin*i;
            cmin=min(min(cmin*i,i),cmax*i);
            cmax=max(max(cmax*i,i),temp);
            res=max(res,cmax);
        }
        return res;
    }
};