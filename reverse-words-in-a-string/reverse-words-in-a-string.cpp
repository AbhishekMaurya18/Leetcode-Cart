class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(c.size()>0){
                    st.push(c);
                    c="";
                }
                continue;
            }   
            c.push_back(s[i]);
        }
        if(c.size()>0)
            st.push(c);
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans.push_back(' ');
            }
        }
        return ans;
    }
};