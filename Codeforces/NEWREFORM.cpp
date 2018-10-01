#include<bits/stdc++.h>
using namespace std;
int vis[100001]={0};
int ans;
void bfs(vector<int> *arr,int n){
  int edges = arr[n].size();
  int vertex = 1;
  queue <int> q;
  q.push(n);
  vis[n]=1;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto u : arr[v]){
      if(vis[u])
      continue;
      vis[u]=1;
      vertex++;
      edges += arr[u].size();
      q.push(u);
    }
  }
  if((edges/2)==(vertex-1))
  ans++;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> arr[n+1];
  for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    arr[x].push_back(y);
    arr[y].push_back(x);
  }
  ans=0;
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      bfs(arr,i);
    }
  }
  cout<<ans<<endl;
}
