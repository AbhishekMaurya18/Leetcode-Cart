class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int old=0,sell=0,buy=INT_MIN;
        
        for(int& i: prices){
            old=sell;
            sell=max(sell,i+buy);
            buy=max(buy,old-i);
        }
        return sell;
    }
};