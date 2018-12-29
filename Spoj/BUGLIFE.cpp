#include<bits/stdc++.h>
using namespace std;

bool isBipartiteUtil(vector<int> *e,int src,int n,int colorArray[]){
  colorArray[src]=1;
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int i=0;i<e[v].size();i++){
      int x = e[v][i];
      if(colorArray[x]==-1){
        q.push(x);
        colorArray[x]=1-colorArray[v];
      }
      if(colorArray[x]==colorArray[v])
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<int> *e,int src,int n){
  int colorArray[n+1];
  for(int i=1;i<=n;i++)
  colorArray[i]=-1;

  // for(int i=1;i<=n;i++){
  //   for(int j=0;j<e[i].size();j++)
  //   cout<<e[i][j]<<" ";
  // }

  for(int i=1;i<=n;i++){
    if(colorArray[i]==-1)
    if(isBipartiteUtil(e,i,n,colorArray)==false)
    return false;
  }
  return true;
}

int main(){
  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    int n,in;
    cin>>n>>in;
    vector<int> e[n+1];
    for(int j=0;j<in;j++){
      int a,b;
      cin>>a>>b;
      e[a].push_back(b);
      e[b].push_back(a);
    }
      cout<<"Scenario #"<<i<<":"<<endl;
      if(isBipartite(e,1,n))
      cout<<"No suspicious bugs found!"<<endl;
      else
      cout<<"Suspicious bugs found!"<<endl;
  }
  return 0;
}
