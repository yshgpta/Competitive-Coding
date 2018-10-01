#include <bits/stdc++.h>
using namespace std;
vector<int> cnt;
void bfs(vector <int> *arr,int n,int* vis){
  vis[n]=1;
  queue <int> q;
  q.push(n);
  long int count=1;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto u : arr[v]){
      if(vis[u])
      continue;
      count++;
      vis[u]=1;
      q.push(u);
    }
  }
  // cout<<count<<" ";
  cnt.push_back(count);
}
int main(){
  int n,p;
  cin>>n>>p;
  vector <int> arr[n];
  while(p--){
    int a,b;
    cin>>a>>b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  int vis[n]={0};
  for(int i=0;i<n;i++){
    if(!vis[i])
    bfs(arr,i,vis);
  }
  // for(int i=0;i<cnt.size();i++){
  //   cout<<cnt[i]<<" ";
  // }
  long long int sum = 0;
  for(int i=0;i<cnt.size();i++){
    for(int j=i+1;j<cnt.size();j++){
      sum += cnt[i]*cnt[j];
    }
  }
  cout<<sum<<endl;
}
