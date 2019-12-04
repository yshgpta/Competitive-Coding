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
vector<vector<pii> > v;
double n,m;
ll l;
bool isValid(ll x,ll y){
    return x>=1 && x<=n && y>=1 && y<=m;
}

void dfsUtil(ll x,ll y,ll len,ll i,vvi &visited){
    if(v.size()==i)
    v.resize(i+1);
    visited[x][y]=1;
    if(len==l){
        len=1;
        i++;
        v.resize(i+1);
    }else{
        len++;
    }
    v[i].pb(mkp(x,y));
    if(isValid(x,y+1) && !visited[x][y+1])
    dfsUtil(x,y+1,len,i,visited);
    if(isValid(x+1,y) && !visited[x+1][y])
    dfsUtil(x+1,y,len,i,visited);
    if(isValid(x,y-1) && !visited[x][y-1])
    dfsUtil(x,y-1,len,i,visited);
    if(isValid(x-1,y) && !visited[x-1][y])
    dfsUtil(x-1,y,len,i,visited);
}

int main(){
   FastIO
   double k;
   cin>>n>>m>>k;
   l = (ll)(n*m)/k;
   vvi visited(305,vi(305,0));
   dfsUtil(1,1,0,0,visited);
   if(v.size()>=k+1){
       for(int j=k;j<v.size();j++){
           for(int i=0;i<v[j].size();i++){
           pii p = v[j][i];
           v[k-1].pb(p);
            }
       }
       v.resize(k);
   }
   for(int i=0;i<v.size();i++){
       cout<<v[i].size()<<" ";
       for(int j=0;j<v[i].size();j++){
           cout<<v[i][j].ff<<" "<<v[i][j].ss<<" ";
       }
       cout<<endl;
   }
   return 0;
}