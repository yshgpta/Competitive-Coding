#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long n,m,p;
    cin>>p>>n>>m;
    set<long> unvisited;
    priority_queue< pair<long, pair<long,long> >,vector<pair<long, pair<long,long> > >,greater<pair<long, pair<long,long> > > > pq;
    vector< vector< pair<long,long> > > adj(n+1);

    for(long i=1;i<=m;i++){
      long s,t,w;
      cin>>s>>t>>w;
      w=w*p;
      adj[s].push_back(make_pair(t,w));
      adj[t].push_back(make_pair(s,w));
    }
    long s=1;
    for(long i=1;i<=n;i++)
    unvisited.insert(i);

    unvisited.erase(s);
    long t,w;
    for(int i=0;i<adj[s].size();i++){
      t=adj[s][i].first;
      w=adj[s][i].second;
      pq.push(make_pair(w,make_pair(s,t)));
    }
    long long sum =0;
    while(!unvisited.empty()){
      pair<long, pair<long,long> > e;
      e=pq.top();
      pq.pop();
      long node = e.second.second;
      if(unvisited.find(node)==unvisited.end())
      continue;
      sum+=e.first;
      unvisited.erase(node);
      for(long i=0;i<adj[node].size();i++){
        t=adj[node][i].first;
        w=adj[node][i].second;
        pq.push(make_pair(w,make_pair(node,t)));
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
