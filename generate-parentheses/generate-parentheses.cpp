class Solution {
public:
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        string op="(";
        solve(n-1,n,op);
        return ans; 
    }
    
    void solve(int open,int close,string op){
    
        if(open==0 and close==0){
            ans.push_back(op);
            return ;
        }
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1);
            op1.pop_back();
        }
        if(close>open){
            string op2=op;
            op2+=")";
            solve(open,close-1,op2);
            op2.pop_back();
        }
        return ;
        
    }
};