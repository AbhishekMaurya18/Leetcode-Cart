class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> count(n,0);
        for(int i : nums){
            count[i]+=i;
        }
        
        int take=0,skip=0;
        
        for(int i=0;i<10001;i++){
            int takei=count[i]+skip;
            int skipi=max(skip,take);
            take=takei;
            skip=skipi;
        }
        return max(skip,take);
    }
};