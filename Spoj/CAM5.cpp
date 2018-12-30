#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,e;
    cin>>n>>e;
    if(e==0){
      cout<<n<<endl;
      return 0;
    }
    vector<int> arr[n];
    for(int i=0;i<e;i++){
      int a,b;
      cin>>a>>b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    queue<int> q;
    bool vis[n]={false};
    int count=0;
    for(int i=0;i<n;i++){
      if(!vis[i]){
        count++;
        vis[i]=true;
        // cout<<"i"<<i<<endl;
        q.push(i);
        while(!q.empty()){
          int v = q.front();
          q.pop();

          for(int j=0;j<arr[v].size();j++){
            int x = arr[v][j];

            if(!vis[x]){
              q.push(x);
              vis[x]=true;
            }
          }
        }
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
