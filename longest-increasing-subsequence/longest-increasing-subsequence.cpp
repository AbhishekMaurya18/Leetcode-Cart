class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        int dp[n];
        map<int,int> cand;
        dp[0]=1;
        cand[nums[0]]=dp[0];
        
        for(int i=1;i<n;i++){
            dp[i]=1+getBestCandidates(cand,nums[i]);
            insert(cand,nums[i],dp[i]);
        }
        
        return *max_element(dp,dp+n);
    }
    
    int getBestCandidates(map<int,int>& cand, int v){
        auto it=cand.lower_bound(v);
        if(it == cand.begin())
            return 0;
        it--;
        return it->second;
    }
    void insert(map<int,int>& cand, int v,int adj){
        if(cand[v]>=adj){
            return ;
        }
        cand[v]=adj;
        auto it=cand.find(v);
        it++;
        
        while(it!=cand.end() && it->second<=adj){
            auto temp=it;
            it++;
            cand.erase(temp);
        }
    }
    
};