int t[3][1001];
class Solution {
public:
    int twoEggDrop(int n) {
        memset(t,-1,sizeof(t));
        return solve(2,n);
    }
    
    int solve(int e,int f){
        int ans;
        if(f<=1 or e==1){
            ans=f;
            return ans;
        }
        if(t[e][f]!=-1){
            return t[e][f];
        }
        else{
            int lo=1,hi=f;
            while(lo+1<hi){
                int x=(lo+hi)/2;
                int t1=solve(e-1,x-1);
                int t2=solve(e,f-x);
                
                if(t1<t2){
                    lo=x;
                }
                else if(t1>t2)
                    hi=x;
                else
                    lo=hi=x;
            }
            ans=1+min(max(solve(e-1,lo-1),solve(e,f-lo)),max(solve(e-1,hi-1),solve(e,f-hi)));
            
        }
        return t[e][f]=ans;
    }
};