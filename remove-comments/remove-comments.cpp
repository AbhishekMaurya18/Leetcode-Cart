class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool block_comment=false;
        string c="";
        
        for(string s: source){
            int n=s.size();
            for(int i=0;i<n;i++){
                
                if(block_comment){
                    if(s[i]=='*' && i<n-1 && s[i+1]=='/'){
                        block_comment=false;
                        i++;
                    }
                }
                else{
                    if(s[i]=='/' && i<n-1 && s[i+1]=='/'){
                        break;
                    }
                    else if(s[i]=='/' && i<n-1 && s[i+1]=='*'){
                        block_comment=true;
                        i++;
                    }
                    else{
                        c.push_back(s[i]);
                    }
                    
                }
            }
            if(!block_comment && c.size()>0){
                ans.push_back(c);
                c="";
            }
        }
        return ans;
    }
};