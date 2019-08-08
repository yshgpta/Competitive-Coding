#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define vpii vector<pair<ll,ll> >
 #define mp make_pair
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 vector<int> adj[100005];
 vector<int> arr(100005);
vector<int> res;
bool visited[100005] = {false};

void dfs(int node){
  visited[node]=true;
  int flag=1;
  for(int i=0;i<adj[node].size();i++){
    int v = adj[node][i];
    if(!visited[v]){
      if(arr[v]==0){
        flag=0;
      }
      dfs(v);
    }
  }
  if(flag==1 && arr[node]==1)
  res.pb(node);
}

 int main(){
 	FastIO
 	int n;
  cin>>n;

  int root;
  for(int i=1;i<=n;i++){
    int p,c;
    cin>>p>>c;
    arr[i]=c;
    if(p==-1){
      root=i;
      continue;
    }
    adj[p].pb(i);
  }
  dfs(root);
  if(res.size()==0)
  cout<<"-1";
  else{
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
      cout<<res[i]<<" ";
    }
  }
 	return 0;
 }
