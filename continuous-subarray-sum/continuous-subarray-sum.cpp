class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum = 0, pre=0;
        unordered_set<int> s;
        //s.insert(0);
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod=(k==0)?sum:sum%k;
            
            if(s.count(mod)){
                return true;
            }
            s.insert(pre);
            pre=mod;
            
        }
        return false;
    }
};