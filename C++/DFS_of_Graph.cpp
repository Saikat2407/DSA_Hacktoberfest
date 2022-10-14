 void dfs(vector<int> &res, vector<bool> &vis,int src,vector<int> adj[]){
        vis[src]=true;
        res.push_back(src);
        
        for(auto &x:adj[src]){
            if(!vis[x])
            dfs(res,vis,x,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<int> res;
        dfs(res,vis,0,adj);
        
       return res;
        
    }
