//ysh_gpta
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



 int main(){
 	FastIO
 	ll t;
  cin>>t;
  while(t--){
    ll m,n;
    cin>>n>>m;
    vi adj[n+1];
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    ll mx=-1;
    for(int i=1;i<=n;i++){
      if(adj[i].size()>mx)
      mx=adj[i].size();
    }
    vi res;
    for(int i=1;i<=n;i++){
      if(mx==adj[i].size())
      res.pb(i);
    }
    ll iter;
    ll sz = res.size();
    n%2==0 ? iter=min(n/2,sz) : iter=min(n/2+1,sz);
    cout<<iter<<endl;
    for(int i=0;i<iter;i++){
      cout<<res[i]<<" ";
    }
    cout<<endl;
  }
 	return 0;
 }
