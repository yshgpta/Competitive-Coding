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
ll n;
ll dp[105];
ll solve(ll sum,ll k){
    if(sum==n)
    return 1;
    if(sum>n)
    return 0;
    if(dp[sum]!=-1)
    return dp[sum];
    ll res=0;
    for(int i=1;i<=k;i++){
        res += solve(sum+i,k)%MOD;
    }
    return dp[sum] = res%MOD;
}

int main(){
   FastIO
   ll d,k;
   cin>>n>>k>>d;
   memset(dp,-1,sizeof(dp));
   ll val1 = solve(0,k);
   memset(dp,-1,sizeof(dp));
   ll val2 = solve(0,d-1);
   if(val1>=val2)
   cout<<val1-val2;
   else
   cout<<val1-val2+MOD;
   return 0;
}