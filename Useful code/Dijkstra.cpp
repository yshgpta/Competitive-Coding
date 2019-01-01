int dijkstra(vector<vector<pair<int,int> > > &adj,int s,int e){
  dist[s]=0;
  priority_queue <pair<int,int>> pq;
  pq.push(make_pair(0,s));
  while(!pq.empty()){
    pair<int,int> p = pq.top();
    pq.pop();
    int u = p.second;

    if(vis[u]) continue;

    int sz = adj[u].size();
    for(int i=0;i<sz;i++){
      int v = adj[u][i].first;
      int cost = adj[u][i].second;
      if(vis[v]) continue;
      if(dist[v]>dist[u]+cost){
        dist[v]=dist[u]+cost;
        pq.push(make_pair(-dist[v],v));
      }
    }
    vis[u]=true;
    if(e==u)
    return dist[e];
  }
}
