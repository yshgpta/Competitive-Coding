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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<endl; cout<<endl; }

vb visited(200005,false);
vvi adj(200005);
vector<set<ll> > vs(200005);
ll index = -1;

void dfs(ll node){
    visited[node]=true;
    vs[index].insert(node);
    for(int i=0;i<adj[node].size();i++){
        ll v = adj[node][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
   FastIO
   ll n,m;
   cin>>n>>m;
   ll a,b;
   for(int i=0;i<m;i++){
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   for(int i=1;i<=n;i++){
       if(!visited[i]){
           index++;
           dfs(i);
       }
   }
   vs.resize(index+1);
   sort(vs.begin(),vs.end());
//    for(int i=0;i<vs.size();i++){
//        for(auto it:vs[i]){
//            cout<<it<<" ";
//        }
//        cout<<endl;
//    }
   if(index==0){
       cout<<0;
       return 0;;
   }
   ll i=0;
   ll mn = *min_element(vs[i+1].begin(),vs[i+1].end());
   ll mx = *max_element(vs[i].begin(),vs[i].end());
   ll cnt=0;
   while(i<index){
       if(mx>mn){
           cnt++;
       }
       i++;
       mx = max(mx,*max_element(vs[i].begin(),vs[i].end()));
       mn = *min_element(vs[i+1].begin(),vs[i+1].end());
   }
   cout<<cnt;
   return 0;
}