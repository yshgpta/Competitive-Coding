#include <bits/stdc++.h>
using namespace std;
long long int ans;
void bfs(vector <long long int> *arr,long long int n,long long int *vis,long long int clib,long long int croad){
  long long nroad;
  vis[n]=1;
  long long edges = arr[n].size();
  long long vertex =1;
  queue <long long int> q;
  q.push(n);
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto u : arr[v]){
      if(vis[u])
      continue;
      vertex++;
      vis[u]=1;
      edges += arr[u].size();
      q.push(u);
    }
  }
  if(edges/2<vertex)
  nroad=edges/2;
  else
  nroad=vertex-1;
  ans += clib + nroad*croad;
}
int main(){
  int q;
  cin>>q;
  while(q--){
    long long int n,m,clib,croad;
    cin>>n>>m>>clib>>croad;
    vector <long long int> arr[n+1];
    long long int vis[n+1]={0};
    ans=0;
    while(m--){
      long long int a,b;
      cin>>a>>b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    if(croad>=clib){
      ans = clib*n;
    }
    else{
      for(long long int i=1;i<=n;i++){
        if(!vis[i])
        bfs(arr,i,vis,clib,croad);
      }
    }
    cout<<ans<<endl;
  }
}
