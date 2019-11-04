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

ll solve(ll x,ll n,ll m){
    ll res = 0;
    x--;
    for(int i=1;i<=n;i++)
    res += min(x/i,m);
    return res;
}

int main(){
   FastIO
   ll n,m,k;
   cin>>n>>m>>k;
   ll low=1;
   ll high = m*n+1;
   while(low<high){
       ll mid = (low+high)/2;
       if(solve(mid,n,m)<k)
       low = mid + 1;
       else
       high = mid;
   }
   cout<<low-1;
   return 0;
}