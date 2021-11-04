class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int chances=minutesToTest/minutesToDie+1;
        
        return ceil(log10(buckets)/log10(chances));
    }
};