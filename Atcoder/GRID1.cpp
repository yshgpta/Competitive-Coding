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
ll n,m;

bool isValid(ll i,ll j){
    if((i>=0 && i<n) && (j>=0 && j<m))
    return true;
    return false;
}


int main(){
   FastIO

   cin>>n>>m;
   vector<string> v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   vvi dp(n,vi(m,0));
   for(int i=0;i<n;i++){
       if(v[i][0]=='#')
       break;
       dp[i][0]=1;
   }
   for(int i=0;i<m;i++){
       if(v[0][i]=='#')
       break;
       dp[0][i]=1;
   }
   for(int i=1;i<n;i++){
       for(int j=1;j<m;j++){
           if(v[i][j]=='#')
           continue;
           if(isValid(i-1,j) && isValid(i,j-1))
           dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
           else if(isValid(i-1,j))
           dp[i][j] = dp[i-1][j];
           else if(isValid(i,j-1))
           dp[i][j] = dp[i][j+1];
       }
   }
//    for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++)
//         cout<<dp[i][j]<<" ";
//         cout<<endl;
//    }

   cout<<dp[n-1][m-1];
   return 0;
}