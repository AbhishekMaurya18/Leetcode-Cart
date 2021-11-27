class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),j=0;
        int ans=0,sum=0;
        map<int,int> m;
        m[0]=1;
        
        while(j<n){
            sum+=nums[j];
            
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
            j++;
            
        }
        return ans;
    }
};