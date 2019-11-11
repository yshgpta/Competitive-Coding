//ysh_gpta
#include<bits/stdc++.h>
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

vvi ve(66);
vector< set<ll> > adj(100005);
vpii edg;

ll bfs(ll a,ll b){
    vb visited(100005,false);
    ll val = INT_MAX;
    queue<pii> q;
    q.push(mkp(a,0));
    visited[a]=true;
    while(!q.empty()){
        pii tp = q.front();
        q.pop();
        ll u = tp.ff;
        ll dis = tp.ss;
        if(b==u){
            val = dis+1;
            break;
        }
        for(auto &v : adj[u]){
            if(u==a && v==b)
            continue;
            if(!visited[v]){
                q.push(mkp(v,dis+1));
                visited[v]=true;
            }
        }
    }
    return val;
}

int main(){
   FastIO
   ll n;
   cin>>n;
   for(int i=0;i<n;i++){
       ll a;
       cin>>a;
       for(int j=0;j<=64;j++){
           if((a >> j)&1)
           ve[j].pb(i);
       }
   }
   for(int i=0;i<=64;i++){
       if(ve[i].size()>=3){
       cout<<3;
       return 0;
       }
   }
   for(int i=0;i<=64;i++){
       for(int j=0;j<ve[i].size();j++){
           for(int k=j+1;k<ve[i].size();k++){
               adj[ve[i][j]].insert(ve[i][k]);
               adj[ve[i][k]].insert(ve[i][j]);
               edg.pb(mkp(ve[i][j],ve[i][k]));
           }
       }
   }
   ll ans = INT_MAX;
   for(auto &u : edg){
       ans = min(bfs(u.ff,u.ss),ans);
   }
   if(ans==INT_MAX)
   cout<<-1;
   else
   cout<<ans;
   return 0;
}