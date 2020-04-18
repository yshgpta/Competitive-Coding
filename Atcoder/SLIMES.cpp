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

ll dp[405][405];
ll sum[405];

ll solve(ll i,ll j){
    if(i>j)
    return 0;
    if(j-i==1)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    ll mn = LONG_LONG_MAX;
    for(ll k=i+1;k<j;k++)
    mn = min(mn,solve(i,k)+solve(k,j)+sum[j]-sum[i]);
    return dp[i][j] = mn;
}

int main(){
   FastIO
   ll n;
   cin>>n;
   vi v(n);
   sum[0] = 0;
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++){
       cin>>v[i];
       sum[i+1] = sum[i]+v[i];
   }
//    for(ll l=2;l<=n;l++){
//        for(ll i=0;i<n-l+1;i++){
//            ll j=i+l-1;
//            if(l==2){
//                dp[i][j]=dp[i][j-1]+dp[i+1][j];
//            }else{
//                dp[i][j] = min(dp[i][j-1]+v[j]+sum[j]-sum[i],dp[i+1][j]+v[i]+sum[j+1]-sum[i+1]);
//            }
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//        cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
   cout<<solve(0,n);
   return 0;
}