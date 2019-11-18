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
   vvi arr(n+1,vi(m+1));
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           cin>>arr[i][j];
       }
   }
   vvi dp1(n+2,vi(m+2,0)),dp2(n+2,vi(m+2,0)),dp3(n+2,vi(m+2,0)),dp4(n+2,vi(m+2,0));
   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   dp1[i][j] = arr[i][j] + max(dp1[i-1][j],dp1[i][j-1]);

   for(int i=n;i>=1;i--)
   for(int j=m;j>=1;j--)
   dp2[i][j] = arr[i][j] + max(dp2[i][j+1],dp2[i+1][j]);

   for(int i=n;i>=1;i--)
   for(int j=1;j<=m;j++)
   dp3[i][j] = arr[i][j] + max(dp3[i+1][j],dp3[i][j-1]);

   for(int i=1;i<=n;i++)
   for(int j=m;j>=1;j--)
   dp4[i][j] = arr[i][j] + max(dp4[i-1][j],dp4[i][j+1]);


   ll max_sum1=0,max_sum2=0;
   for(int i=2;i<=n-1;i++){
       for(int j=2;j<=m-1;j++){
           max_sum1 = max(max_sum1,dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
           max_sum2 = max(max_sum2,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
       }
   }
   cout<<max(max_sum1,max_sum2);
   return 0;
}