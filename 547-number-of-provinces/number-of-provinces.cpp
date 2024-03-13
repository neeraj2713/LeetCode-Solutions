class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //creating adjacency list
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int provinces = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                provinces++;
                dfs(i, adj, vis);
            }
        }

        return provinces;

    }
};