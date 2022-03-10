void dijkstra(int src,vector<vector<pair<int,int>>>&graph,int n)
{
    vector<int>result(n,INT_MAX);

    result[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();

        if(curD>result[u])continue;

        for(auto it:graph[u])
        {
            int v = it.first;
            int cost = it.second;

            if(result[v]>cost+curD)
            {
                result[v] = cost+curD;
                pq.push({result[v],v});
            }
        }
    }
}
