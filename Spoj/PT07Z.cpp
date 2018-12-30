#include<bits/stdc++.h>
using namespace std;
vector<int> e[10005];
int x;

void dfsUtil(int node,int count,int& maxCount,bool* vis){
  vis[node]=true;
  count++;
  for(int i = 0;i<e[node].size();i++){
    int v = e[node][i];
    if(!vis[v]){
      if(count>=maxCount){
        maxCount=count;
        x=v;
      }
      dfsUtil(v,count,maxCount,vis);
    }
  }
}

void dfs(int node,int n,int& maxCount){
  bool vis[n+1]={false};
  int count=0;
  dfsUtil(node,count,maxCount,vis);
}

int maxLenght(int node,int n){
  int maxCount=-2;
  dfs(node,n,maxCount);
  dfs(x,n,maxCount);
  return maxCount;
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  cout<<maxLenght(1,n);
  return 0;
}
