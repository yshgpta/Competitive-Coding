#include <bits/stdc++.h>
using namespace std;
int main(){
  int num;
  cin>>num;
  int a[num+1],p[num+1];
  int root;
  vector <int> e[num+1];
  for(int i=1;i<=num;i++)
  cin>>a[i];
  for(int i=1;i<=num;i++){
    cin>>p[i];
    if(p[i]==-1){
      root=i;
      continue;
    }
    e[p[i]].push_back(i);
  }
  queue <int> q;
  bool vis[num+1]={false};
  q.push(root);
  vis[root]=true;
  int v,x,ans=0;
  int mx[num+1];
  mx[root]=a[root];
  while(!q.empty()){
    v = q.front();
    q.pop();

    for(int i=0;i<e[v].size();i++){
      x=e[v][i];

      if(!vis[x]){
        q.push(x);
        vis[x]=true;
        ans=max(ans,mx[v]-a[x]);
        mx[x]=max(mx[v],a[x]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
