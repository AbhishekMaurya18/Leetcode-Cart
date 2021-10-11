class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        unordered_set<string> ws;
        
        for(string& c: wordDict){
            ws.insert(c);
        }
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            string word="";
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(ws.find(word)!=ws.end()){
                    if(dp[j+1]){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};