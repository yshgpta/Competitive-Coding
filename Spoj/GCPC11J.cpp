#include<bits/stdc++.h>
using namespace std;
vector<int> e[10005];
int x;

void dfsUtil(int node,int count,int& maxCount,bool* vis,vector<int>* e){
  vis[node]=true;
  count++;
  for(int i = 0;i<e[node].size();i++){
    int v = e[node][i];
    if(!vis[v]){
      if(count>=maxCount){
        maxCount=count;
        x=v;
      }
      dfsUtil(v,count,maxCount,vis,e);
    }
  }
}

void dfs(int node,int n,int& maxCount,vector<int>* e){
  bool vis[n+1]={false};
  int count=0;
  dfsUtil(node,count+1,maxCount,vis,e);
}

int maxLenght(int node,int n,vector<int>* e){
  int maxCount=-2;
  dfs(node,n,maxCount,e);
  dfs(x,n,maxCount,e);
  return maxCount;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> e[n];
    for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      e[a].push_back(b);
      e[b].push_back(a);
    }
    // if(n==2){
    //   cout<<1<<endl;
    //   return 0;
    // }
    cout<<maxLenght(0,n,e)/2<<endl;
  }
  return 0;
}
