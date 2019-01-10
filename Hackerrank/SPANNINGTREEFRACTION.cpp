#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
bool visited[MAX];
vector<vector<pair<int ,pair<int,int> > > > adj(MAX);
priority_queue<pair<pair<double,int>,pair<int,int> > > pq;
long sumA,sumB;

void prim(int u,double x){
  double temp;
  visited[u]=true;
  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i].first;
    if(visited[v])
    continue;
    int a = adj[u][i].second.first;
    int b = adj[u][i].second.second;
    temp = (double)a-b*x;
    pq.push(make_pair(make_pair(temp,v),make_pair(a,b)));
  }
}

bool mst(double x){
  double max_cost = 0.0;
  sumA=0;
  sumB=0;
  memset(visited,0,sizeof(visited));
  prim(0,x);
  while(!pq.empty()){
    pair<pair<double,int>,pair<int,int> > e;
    e = pq.top();
    pq.pop();
    int w = e.first.first;
    int v = e.first.second;
    int a = e.second.first;
    int b = e.second.second;
    if(!visited[v]){
      max_cost += w;
      sumA+=a;
      sumB+=b;
      prim(v,x);
    }
  }
  if(max_cost>=0)
  return true;
  return false;
}

int gcd(int a,int b){
  if(b==0)
  return a;
  return gcd(b,a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  double mid,low=0.0,hi=10000000.0;
  for(int i=0;i<m;i++){
    int u,v,a,b;
    cin>>u>>v>>a>>b;
    adj[u].push_back(make_pair(v,make_pair(a,b)));
    adj[v].push_back(make_pair(u,make_pair(a,b)));
  }
  for(int i=1;i<=65;i++){
    mid = low+(hi-low)/2.0;
    if(mst(mid))
    low = mid;
    else
    hi = mid;
  }
  mst(low);
  int div = gcd(sumA,sumB);
  int numerator = sumA/div;
  int denominator = sumB/div;
  cout<<numerator<<"/"<<denominator;
  return 0;
}
