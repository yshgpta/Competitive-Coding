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
#define vs vector<string>
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

vs adj;
vb vis(1003);


int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n,k;
       cin>>n>>k;
       for(int i=0;i<1003;i++)
       vis[i]=false;
       adj.clear();
       for(int i=0;i<n;i++){
           string str;
           cin>>str;
           adj.push_back(str);
       }
       queue<pii> q;
       q.push(mkp(0,0));
       vis[0]=true;
       ll res;
       while(!q.empty()){
           ll v = q.front().ff;
           ll d = q.front().ss;
           q.pop();
           if(v==n-1){
               res = d;
               break;
           }
           for(int i=0;i<adj[v].size();i++){
               if(adj[v][i]=='1' && !vis[i] && abs(v-i)<=k){
                   vis[i]=true;
                   q.push(mkp(i,d+1));
               }
           }
       }
       if(vis[n-1])
       cout<<res<<endl;
       else
       cout<<-1<<endl;
   }
   return 0;
}