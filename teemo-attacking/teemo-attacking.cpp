class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        for(int i=0;i<timeSeries.size()-1;++i){
            res+=min(timeSeries[i+1]-timeSeries[i],duration);
        }
        res+=duration;
        return res;
    }
};