class Solution {
public:
    vector<int> visited;
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        //build adj list for graph
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        visited.resize(n,false);
        stack<int> s;
        s.push(start);
        
        while(!s.empty()){
            int t=s.top();
            
            if(t==end){
                return 1;
            }
            s.pop();
            visited[t]=true;
            
            for(auto i: adj[t]){
                if(visited[i]!=true)
                    s.push(i);
            }
        }
        return false;
    }
    
};