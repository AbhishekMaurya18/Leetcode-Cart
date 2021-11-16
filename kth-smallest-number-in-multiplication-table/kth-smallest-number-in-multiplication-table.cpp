class Solution {
public:
    bool enough(int mid,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(mid/i,n);
        }
        return count>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            
            if(!enough(mid,m,n,k)){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return lo;
    }
};