class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        
        int n=envelopes.size();
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++){
            int j=i-1;
            while(j>=0){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                j--;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};