class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        int ans=0,cheapest=prices[0];
        
        for(int i=1;i<n;i++){
            ans=max(ans,prices[i]-cheapest);
            cheapest=min(cheapest,prices[i]);
        }
        return ans;
    }
};