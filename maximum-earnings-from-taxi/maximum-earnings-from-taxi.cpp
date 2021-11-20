class Solution {
public:
    #define ll long long
    #define pii pair<int,int>
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
       
        vector<vector<pii>> startpoint(n);
        for(auto v: rides){
            int s=v[0],e=v[1],r=v[2];
            startpoint[s].push_back({e,e-s+r});
        }
        
        vector<ll> dp(n+1);
        
        for(int i=n-1;i>=1;i--){
            for(auto [e,d]: startpoint[i]){
                dp[i]=max(dp[i],dp[e]+d);
            }
            //cout<<dp[i];
            dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[1];
        
    }
    
    
    
    
    
//     static bool comp(vector<int>&v1, vector<int>&v2){
//         return v1[1]<v2[1];
//     }
    
//     int findbest(vector<int>&endpoints, int val){
//         auto t=lower_bound(endpoints.begin(),endpoints.end(),val)-endpoints.begin();
        
//         return t==0?-1:t-1;
        
//     }
    
//     long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
//         //sort(rides.begin(),rides.end(),comp);
        
//         //return solve(rides);
//     }
    
//     long long solve(vector<vector<int>>&ride){
        
//         vector<int> endp;
//         for(auto v: ride){
//             endp.push_back(v[1]);
//         }
        
//         int n=ride.size();
//         vector<ll> dp(n+1,0);
//         //dp[0]=0;
        
//         for(int i=1;i<=n;i++){
//             ll op1=dp[i-1];
//             ll op2=ride[i][2]+(ride[i][1]-ride[i][0]);
//             int j=findbest(endp,ride[i][0]);
            
//             op2+=dp[j];
//             dp[i]=max(op1,op2);
            
//         }
        
//         return dp[n];
        
//     }
};