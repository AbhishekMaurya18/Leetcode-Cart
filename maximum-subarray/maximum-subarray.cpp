class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=-10000,maxx=INT_MIN;
        
        for(int i: nums){
            cur=max(i,cur+i);
            maxx=max(maxx,cur);
        }
        return maxx;
    }
};