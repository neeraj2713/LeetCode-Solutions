#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // vector<pair<int, int>> adj[n];
        // for(auto it : roads){
        //     adj[it[0]].push_back({it[1], it[2]});
        //     adj[it[1]].push_back({it[0], it[2]});
        // }
        
        // priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // vector<int> dist(n, 1e9), ways(n, 0);
        // dist[0] = 0;
        // ways[0] = 1;
        // pq.push({0, 0});
        // int mod = (long long)(1e18 + 7);

        // while(!pq.empty()){
        //     int dis = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();

        //     for(auto it : adj[node]){
        //         int adjNode = it.first;
        //         int edW = it.second;

        //         if(dis + edW < dist[adjNode]){
        //             dist[adjNode] = edW + dis;
        //             pq.push({dis+edW, adjNode});
        //             ways[adjNode] = ways[node];
        //         } else if(dis + edW == dist[adjNode]){
        //             ways[adjNode] = (ways[adjNode] + ways[node])%mod;
        //         }
        //     } 
        // }
        

        // return ways[n-1]%mod;


        ll u,v,w,node,d,adjnode,edw;
        vector<pair<ll,ll>>adj[n];
        // vector<pair<ll,pair<ll,ll>>>adj;
        for(auto i:roads)
        {
            u=i[0];
            v=i[1];
            w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<ll>dist(n,1e18),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        ll mod=(ll)(1e9+7);
        while(!pq.empty()){
            d=pq.top().first;
            node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                adjnode=i.first;
                edw=i.second;
                if(d+edw<dist[adjnode])
                {
                    dist[adjnode]=d+edw;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }else if(d+edw==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;

    }
};