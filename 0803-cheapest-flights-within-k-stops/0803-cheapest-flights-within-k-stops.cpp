class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;

        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        int minprice = INT_MAX;
        dist[src] = 0;
        q.push({0,{0,src}});
        while(!q.empty()){
            int top_node = q.front().second.second;
            int top_price = q.front().second.first;
            int top_steps = q.front().first;
            if(top_steps>k) break;
            q.pop();
            for(auto it: adj[top_node]){
                if(top_price + it.second < dist[it.first]){
                    dist[it.first] = top_price + it.second;
                    q.push({top_steps+1,{dist[it.first], it.first}});
                    if(it.first == dst and top_steps<=k){
                        minprice = min(minprice,dist[it.first]);
                    }
                } 
            }
        }
        // for(auto it: dist){
        //     cout << it << " ";
        // }
        // cout << endl;
        if(dist[dst] == INT_MAX) return -1;
        return minprice;
    }
};