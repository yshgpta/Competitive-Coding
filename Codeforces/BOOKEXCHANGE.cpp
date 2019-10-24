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
vi parent(200005);
ll find(ll u){
    if(u!=parent[u]){
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void dfs(ll node,vb &visited,vvi &adj){
    visited[node]=true;
    ll u = find(parent[node]);
    for(int i=0;i<adj[node].size();i++){
        ll x = adj[node][i];
        if(visited[x]){
            parent[node]=u;
            return;
        }else{
            ll v = find(parent[x]);
            if(u!=v)
            parent[x] = u;
            dfs(x,visited,adj);
        }
    }
}

int main(){
   FastIO
   ll q;
   cin>>q;
   while(q--){
       ll n;
       cin>>n;
       vi va(n+1);
       vvi adj(n+1);
       for(int i=1;i<=n;i++){
           cin>>va[i];
           parent[i]=i;
           adj[i].pb(va[i]);
       }
       vb visited(n+1);
       for(int i=1;i<=n;i++){
           if(!visited[i])
           dfs(i,visited,adj);
       }
       map<ll,ll> mp;
       for(int i=1;i<=n;i++){
           mp[parent[i]]++;
       }
       for(int i=1;i<=n;i++){
           cout<<mp[parent[i]]<<" ";
       }
       parent.clear();
       cout<<endl;
   }
   return 0;
}