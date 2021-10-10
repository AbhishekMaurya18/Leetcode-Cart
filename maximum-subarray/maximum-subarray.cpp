class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=INT_MIN,csum=0;
        
        for(int i : nums){
            csum=max(csum+i,i);
            msum=max(csum,msum);
        }
        
        return msum;
        
    }
};