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
void printArray(vi &v){for(int i=0;i<15;i++) cout<<v[i]<<" "; cout<<endl; }

vi dp(100005,1);
vi pf[100005];
vb p(100005,true);
void initialize(){
   for(int i=2;i<=100000;i++){
      if(p[i]){
         pf[i].pb(i);
         for(int j=i*2;j<=100000;j+=i){
            p[j]=false;
            pf[j].pb(i);
         }
      }
   }
}

int main(){
   FastIO
   initialize();
   ll n;
   cin>>n;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   ll ans=1;
   for(int i=0;i<n;i++){
      ll a = 1;
      for(int j:pf[v[i]]){
         a= max(a,dp[j]);
      }
      ans = max(ans,a);
      for(int j:pf[v[i]]){
         dp[j] = max(a+1,dp[j]);
      }
   }
   // printArray(dp);
   cout<<ans;
   return 0;
}