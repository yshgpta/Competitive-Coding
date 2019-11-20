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
int main(){
   FastIO
   ll n,m;
   cin>>n>>m;
   vpii v(n);
   for(int i=0;i<n;i++){
       ll x,s;
       cin>>x>>s;
       v[i].ff = max((ll)0,x-s);
       v[i].ss = min(m,x+s);
   }
   vi dp(m+1);
   dp[m]=0;
   for(int i=m-1;i>=0;i--){
       dp[i] = m-i;
       for(int j=0;j<n;j++){
           ll left = v[j].ff;
           ll right = v[j].ss;
           if(left<=i && right-1>=i){
               dp[i] = dp[i+1];
               break;
           }
           if(i<left){
               ll cost = left-i-1;
               ll nexti = min(m,right + cost);
               dp[i] = min(dp[i],cost+dp[nexti]);
           }
       }
   }
   cout<<dp[0];

   return 0;
}