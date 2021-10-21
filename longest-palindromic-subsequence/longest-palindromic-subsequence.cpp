class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b=a;
        reverse(a.begin(),a.end());
        
        int n=a.size();
        
        int t[n+1][n+1];
        
        //initialization
        for(int i=0;i<=n;i++){
            t[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            t[0][j]=0;
        }
        
        //LCS code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][n];
        
    }
};