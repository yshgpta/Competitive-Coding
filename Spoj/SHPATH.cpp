#include <bits/stdc++.h>
using namespace std;
#define mxn 100005
#define INF 1000000000
int dist[mxn];
bool vis[mxn];
void initialise(){
  for(int i=0;i<mxn;i++){
    dist[i]=INF;
    vis[i]=false;
  }
}

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

int main(){
  int t;
  cin>>t;
  initialise();
  while(t--){
    int num;
    cin>>num;
    map <string,int> mep;
    vector < vector< pair < int, int > > > adj(num+1);
    for(int i=1;i<=num;i++){
      string name;
      cin>>name;
      mep.insert(make_pair(name,i));
      int p;
      cin>>p;
      for(int j=1;j<=p;j++){
        int v,c;
        cin>>v>>c;
        adj[i].push_back(make_pair(v,c));
      }
    }
    int q;
    cin>>q;
    string beg,end;
    for(int i=0;i<q;i++){
      cin>>beg>>end;
      cout<<dijkstra(adj,mep[beg],mep[end])<<endl;
      initialise();
    }
  }
  return 0;
}
