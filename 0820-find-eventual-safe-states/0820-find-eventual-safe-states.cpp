class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            safeNodes.push_back(x);
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};