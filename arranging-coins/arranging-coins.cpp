class Solution {
public:
    int arrangeCoins(int n) {
        int l=1,r=n,ans=1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(Solve(mid,n)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    bool Solve(int m, int n){
        long long k=m,r=n;
        if((k*(k+1)/2)<=r){
            return true;
        }
        return false;
    }
};