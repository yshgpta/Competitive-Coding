#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  set<int> unvisited;
  priority_queue< pair<int, pair<int,int> >,vector<pair<int, pair<int,int> > >,greater<pair<int, pair<int,int> > > > pq;
  vector< vector< pair<int,int> > > adj(n+1);

  for(int i=1;i<=m;i++){
    int s,t,w;
    cin>>s>>t>>w;
    adj[s].push_back(make_pair(t,w));
    adj[t].push_back(make_pair(s,w));
  }
  int s;
  cin>>s;
  for(int i=1;i<=n;i++)
  unvisited.insert(i);

  unvisited.erase(s);
  int t,w;
  for(int i=0;i<adj[s].size();i++){
    t=adj[s][i].first;
    w=adj[s][i].second;
    pq.push(make_pair(w,make_pair(s,t)));
  }
  long sum =0;
  while(!unvisited.empty()){
    pair<int, pair<int,int> > e;
    e=pq.top();
    pq.pop();
    int node = e.second.second;
    if(unvisited.find(node)==unvisited.end())
    continue;
    sum+=e.first;
    unvisited.erase(node);
    for(int i=0;i<adj[node].size();i++){
      t=adj[node][i].first;
      w=adj[node][i].second;
      pq.push(make_pair(w,make_pair(node,t)));
    }
  }
  cout<<sum<<endl;
  return 0;
}
