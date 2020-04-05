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
ll n;

ll dp[3005][3005][2];

ll solve(ll i,ll j,bool t,vi &v){
    if(i>j) return 0;
    if(dp[i][j][t]!=-1)
    return dp[i][j][t];
    if(t){
        return dp[i][j][t] = max(solve(i+1,j,!t,v)+v[i],solve(i,j-1,!t,v)+v[j]);
    }else{
        return dp[i][j][t] = min(solve(i+1,j,!t,v)-v[i],solve(i,j-1,!t,v)-v[j]);
    }
}

int main(){
   FastIO
   
   cin>>n;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   memset(dp,-1,sizeof(dp));
   cout<<solve(0,n-1,true,v);
   return 0;
}