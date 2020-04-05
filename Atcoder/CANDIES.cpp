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

vvi dp(105,vi(100005,0));
vvi s(105,vi(100005,0));

int main(){
   FastIO
   ll n,k;
   cin>>n>>k;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
//    sort(v.begin(),v.end());
   vvi dp(105,vi(100005,0));
    vvi s(105,vi(100005,0));

   dp[0][0]=1;
   s[0][0]=1;
   for(int i=1;i<n;i++){
       dp[i][0] = 1;
       s[i][0] = 1;
   }
   ll sum = 0;
   for(int i=0;i<n;i++){
       sum+=v[i];
       ll c=1;
       for(int j=1;j<=k;j++){
           if(i==0 && j<=sum)
           dp[i][j]=1;
           else if(sum==j){
               dp[i][j]=1;
           }else if(j>sum){
               dp[i][j] = 0;
           }
           else{
               dp[i][j] = s[i-1][j];
               if(j-v[i]-1>=0)
               dp[i][j] -= s[i-1][j-v[i]-1];
           }
           dp[i][j] = (dp[i][j]+MOD)%MOD;
           c = (c + dp[i][j])%MOD;
           s[i][j] = c;
       }
   }

//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=k;j++)
//        cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
//       for(int i=0;i<=n;i++){
//        for(int j=0;j<=k;j++)
//        cout<<s[i][j]<<" ";
//        cout<<endl;
//    }
   cout<<dp[n-1][k];
   return 0;
}