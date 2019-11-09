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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<
//; cout<<endl; }
ll dp[101][101][11][11];

int main(){
   FastIO
   memset(dp,0,sizeof(dp));
   ll n1,n2,k1,k2;
   cin>>n1>>n2>>k1>>k2;
   ll MD = 100000000;
   for(int i=0;i<=n1;i++){
       for(int j=0;j<=n2;j++){
           for(int k=0;k<=k1;k++){
               for(int l=0;l<=k2;l++){
                   ll ans =0;
                   if(i==0 && j==0)
                   ans = 1;
                   else{
                       if(i>0 && k>0){
                           ans+=dp[i-1][j][k-1][k2];
                           ans%=MD;
                       }
                       if(j>0 && l>0){
                           ans += dp[i][j-1][k1][l-1];
                           ans %= MD;
                       }
                   }
                   dp[i][j][k][l] = ans;
               }
           }
       }
   }
   cout<<dp[n1][n2][k1][k2];
   return 0;
}