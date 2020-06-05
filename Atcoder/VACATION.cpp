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
   ll n;
   cin>>n;
   vvi v(n,vi(3));
   for(int i=0;i<n;i++)
   cin>>v[i][0]>>v[i][1]>>v[i][2];

   vvi dp(n,vi(3));
   dp[0][0] = v[0][0];
   dp[0][1] = v[0][1];
   dp[0][2] = v[0][2];
   for(int i=1;i<n;i++){
       dp[i][0] = v[i][0] + max(dp[i-1][1],dp[i-1][2]);
       dp[i][1] = v[i][1] + max(dp[i-1][0],dp[i-1][2]);
       dp[i][2] = v[i][2] + max(dp[i-1][0],dp[i-1][1]); 
   }
   cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
   return 0;
}