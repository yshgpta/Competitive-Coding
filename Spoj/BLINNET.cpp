#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
vector<int> parent(MAX);

int find(int u){
  if(u!=parent[u])
  parent[u]=find(parent[u]);
  return parent[u];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector< pair<int,pair<int,int> > > arr(n+1);
    parent.clear();
    for(int i=1;i<=n;i++){
      parent[i]=i;
      string name;
      cin>>name;
      int e;
      cin>>e;
      while(e--){
        int v,w;
        cin>>v>>w;
        if(v>i)
        arr.push_back(make_pair(w,make_pair(i,v)));
      }
    }
    sort(arr.begin(),arr.end());
    long cost=0;
    for(int i=0;i<arr.size();i++){
      int u = find(arr[i].second.first);
      int v = find(arr[i].second.second);
      int w = arr[i].first;
      if(u!=v){
        cost+=w;
        parent[u]=parent[v];
      }
    }
    cout<<cost<<endl;
  }
  return 0;
}
