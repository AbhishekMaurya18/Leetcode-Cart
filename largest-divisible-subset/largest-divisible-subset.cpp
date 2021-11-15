class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<int> t(n,0),parent(n,0),ans;
        
        int m=0,index=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                
                if(nums[j]%nums[i]==0 && t[i]<1+t[j]){
                    t[i]=1+t[j];
                    parent[i]=j;
                    
                    if(t[i]>m){
                        m=t[i];
                        index=i;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            ans.push_back(nums[index]);
            index=parent[index];
        }
        return ans;
        
    }
};