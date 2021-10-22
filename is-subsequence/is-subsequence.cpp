class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),k=t.size();
        if(n==0){
            return true;
        }
        if(k==0){
            return false;
        }
        map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        int count=m.size(),i=0;
        
        for(char c: t){
            if(c==s[i] && m[c]>0){
                m[c]--;
                i++;
                if(m[c]==0){
                    count--;
                }
            }
            if(count==0){
                return true;
            }
        }
        return false;
    }
};