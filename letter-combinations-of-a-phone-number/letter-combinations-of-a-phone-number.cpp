class Solution {
public:
    
    vector<string> ans,pad={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size())
            solve("",digits,0);
        return ans;
    }
    
    void solve(string op, string d, int i){
        if(i==d.size()){
            ans.push_back(op);
            return;
        }
        for(char c: pad[d[i]-'2']){
            op.push_back(c);
            solve(op,d,i+1);
            op.pop_back();
        }
        return ;
    }
};