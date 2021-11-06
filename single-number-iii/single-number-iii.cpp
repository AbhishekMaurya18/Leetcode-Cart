class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i: nums){
            x^=i;
        }
        
        int a=0,b=0,i=0;
        
        while(((x>>i)&1)!=1){
            i++;
        }
        
        for(int j: nums){
            if((j>>i)&1==1){
                a^=j;
            }
            else{
                b^=j;
            }
        }
        return {a,b};
    }
};