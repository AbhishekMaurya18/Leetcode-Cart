class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix_sum=INT_MAX,cur=0;
        
        for(int i: nums){
            cur+=i;
            prefix_sum=min(prefix_sum,cur);
        }
        
        return prefix_sum>0?1:abs(prefix_sum)+1;
    }
};