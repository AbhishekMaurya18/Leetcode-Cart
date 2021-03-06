class Solution {
public:
    vector<vector<int>> ans,adjList;
    vector<int> disc,low,parent;
    int time;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(n==2){
            return connections;
        }
        //sort(connections.begin(),connections.end());
        adjList.resize(n);
        disc.resize(n,-1);
        low.resize(n,-1);
        parent.resize(n,-1);
        time = 0;
        
        //build undirected graph
        for(auto& conn : connections)
        {
            adjList[conn[1]].push_back(conn[0]);
            adjList[conn[0]].push_back(conn[1]);
        }

        tarjanBridge(n);
        
        return ans;
    }
    
    void tarjanBridge(int n){
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i);
            }
        }
        return ;
    }
    
    void dfs(int node){
        //update discovery and low valuesfor a node that has not been visited earier
        //update timer
        disc[node] = low[node] = time++;
        
        //dfs on all the nodes that are connected from the current node
        for(int i = 0; i < adjList[node].size(); ++i)
        {
            int child = adjList[node][i];
            //if node has not been visited before
            if(disc[child] == -1)
            {
                //update parent information for child node
                parent[child] = node;
                dfs(child);
                
                //while backtracking, update low value of parent to check if there is a back-edge
                low[node] = min(low[node],low[child]);
                
                //check if the edge is a bridge and not a back-edge from child/sub-graph of child
                //to it's parent or any of it's ancestors
                if(low[child] > disc[node])
                    ans.push_back({node,child});
            }
            //check just for a single back-edge
            else if(child != parent[node])
                //check and update if the ancestor was discovered before the earliest connected node to our current node
                low[node] = min(low[node],disc[child]);
        }
    }
};