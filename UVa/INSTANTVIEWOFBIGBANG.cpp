#include <bits/stdc++.h>
using namespace std;
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second.first
#define tt            second.second
#define all(a)        a.begin(),a.end()
#define INF           1000000000
#define mxn           1010

typedef pair< int,pair<int,int> > piii;
typedef vector< piii > viii;

bool vis[mxn];
int dist[mxn];
queue<int> cycle;
vector<int> nodes;
int n , e; //no. of nodes & edges

bool BellmanFord(viii& edg){
    fill(dist, dist+mxn, INF);
    dist[n] = 0;
    int u, v, cost;

    bool upd = true;
    for(int i=1; i<=n && upd; i++){
        upd = false;
        for(int j=0; j<=e; j++){
            u = edg[j].ff; v = edg[j].ss; cost = edg[j].tt;
            if(dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                upd = true;
            }
        }
    }
    for(int j=0; j<=e; j++){
        u = edg[j].ff; v = edg[j].ss; cost = edg[j].tt;
        if(dist[v]>dist[u]+cost){
            dist[v] = dist[u] + cost;
            cycle.push(v);
            cycle.push(u);
        }
    }
}

void BFS(vector<int> adj[]){
    fill(vis, vis+mxn, false);
    while(!cycle.empty()){
        int u = cycle.front(); cycle.pop();
        if(!vis[u]) nodes.pb(u);
        vis[u] = true;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]) cycle.push(v);
        }
    }
}

int main()
{

    int t; cin>>t;
    for(int tc = 1; tc<=t; tc++){
        cin>>n>>e;

        int u , v , w;

        viii edg;
        vector<int> adj[n+1];

        for(int i=0; i<e; i++){
            cin>>u>>v>>w;
            edg.pb(mp(v, mp(u,w)));
            adj[v].pb(u);
        }
        for(int i=0; i<n; i++){
            edg.pb(mp(n, mp(i,0)));
            adj[n].pb(i);
        }

        BellmanFord(edg);

        BFS(adj);

        sort(all(nodes));

        cout<<"Case "<<tc<<":";
        if(nodes.empty()) cout<<" impossible\n";
        else{
            for(int i=0; i<nodes.size(); i++) cout<<' '<<nodes[i];
            cout<<endl;
        }
        nodes.clear();
    }

    return 0;
}
