//ysh_gpta
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
#define vb vector<bool>
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define mkp make_pair
#define pb push_back
#define INF 1000000000000000
#define MOD 1000000007
#define ff first
#define ss second
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
ll n,m;
void printArray(vi &v){for(int i=1;i<=n;i++) cout<<v[i]<<" "; cout<<endl; }

vi dp(100005,0);
vb vis(100005,false);
vi in_degree(100005,0);


void dfsUtil(vvi &adj,int i){
    vis[i]=true;
    for(int j=0;j<adj[i].size();j++){
        dp[adj[i][j]] = max(dp[adj[i][j]],dp[i]+1);
        in_degree[adj[i][j]]--;
        if(in_degree[adj[i][j]]==0)
        dfsUtil(adj,adj[i][j]);
    }
}
void dfs(vvi adj){
    for(int i=1;i<=n;i++){
        if(!vis[i] && in_degree[i]==0){
            dfsUtil(adj,i);
        }
    }
}

int main(){
   FastIO
   cin>>n>>m;
   vvi adj(n+1);
   for(int i=1;i<=m;i++){
       int a,b;
       cin>>a>>b;
       adj[a].pb(b);
       in_degree[b]++;
   }
   dfs(adj);
//    printArray(dp);
   cout<<*max_element(dp.begin(),dp.end());
   return 0;
}