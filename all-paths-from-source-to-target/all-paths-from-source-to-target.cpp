class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q;
        int n=graph.size()-1;
        q.push({0});
        vector<vector<int>> ans;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                vector<int> cur=q.front();
                q.pop();
                int l=cur.back();
                
                for(int i=0;i<graph[l].size();i++){
                    cur.push_back(graph[l][i]);
                    if(graph[l][i]==n){
                        ans.push_back(cur);
                    }
                    else{
                        q.push(cur);
                    }
                    cur.pop_back();
                }
            }
        }
       return ans; 
    }
};