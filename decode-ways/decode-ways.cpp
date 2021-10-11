class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=s[0]!='0'?1:0;
        
        for(int i=2;i<=n;i++){
            int one=stoi(s.substr(i-1,1));
            int second=stoi(s.substr(i-2,2));
            if(one>=1 && one<=9){
                dp[i]+=dp[i-1];
            }
            if(second>=10 && second<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};