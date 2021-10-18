class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> m;
        
        for(auto& c: wordDict){
            m.insert(c);
        }
        int dp[n+1];
        memset(dp,0,sizeof dp);
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            string word="";
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(m.find(word)!=m.end()){
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