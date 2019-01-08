  #include<bits/stdc++.h>
  #define MAX 100005
  using namespace std;

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
      int n,m;
      cin>>n>>m;
      parent.clear();
      vector<int> citizen(n+1);
      vector<pair<int,pair<int,int> > > arr;
      parent[0]=0;
      for(int i=1;i<=n;i++){
        parent[i]=i;
        cin>>citizen[i];
        if(citizen[i]==1)
        arr.push_back(make_pair(0,make_pair(0,i)));
      }

      for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr.push_back(make_pair(w,make_pair(u,v)));
      }
      long long cost=0;
      sort(arr.begin(),arr.end());
      for(int i=0;i<arr.size();i++){
        int u = find(arr[i].second.first);
        int v = find(arr[i].second.second);
        int w = arr[i].first;
        if(u!=v){
          parent[u]=parent[v];
          cost+=w;
        }
      }
      bool flag=true;
      for(int i=1;i<=n;i++){
        if(find(i)!=find(i-1)){
          flag=false;
          break;
        }
      }
      if(flag)
      cout<<cost<<endl;
      else
      cout<<"impossible"<<endl;
    }
    return 0;
  }
