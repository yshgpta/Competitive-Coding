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
   vector<double> v(n+1);
   for(int i=1;i<=n;i++)
   cin>>v[i];
   double dp[n+1][n+1];
   memset(dp,0.0,sizeof(dp));
   dp[0][0] = 1.0;
   for(int i=1;i<=n;i++){
       for(int j=0;j<=i;j++){
           if(j==0)
           dp[i][j] = dp[i-1][j]*(1-v[i]);
           else
           dp[i][j] = dp[i-1][j]*(1-v[i]) + dp[i-1][j-1]*v[i];
       }
   }
   double ans = 0.0;
   for(int i=(n+1)/2;i<=n;i++){
       ans += dp[n][i];
   }
   printf("%0.9f",ans);
   return 0;
}