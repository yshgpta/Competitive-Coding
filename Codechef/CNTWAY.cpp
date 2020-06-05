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
   ll t;
   cin>>t;
   while(t--){
       ll n,l;
       cin>>n>>l;
       if(n%2==1){
           cout<<0<<endl;
           continue;
       }
       ll dp[l+1][n+1];
       memset(dp,0,sizeof(dp));
       for(int i=2;i<=l;i+=2){
           vi sum(n+1,0);
           for(int j=2;j<=n;j+=2){
               if(j<=i)
                dp[i][j]=dp[i-2][j];
               if(i==j){
                   dp[i][j]+=1;
               }else if(j>i){
                   dp[i][j] += (sum[j-2] - sum[j-i-2]);
               }
               sum[j] = sum[j-2] + dp[i][j];
           }
        //    cout<<"Sum"<<endl;
        //    for(int k=0;k<=n;k+=2)
        //    cout<<sum[k]<<" ";
        //    cout<<endl;
       }
       for(int i=2;i<=l;i+=2){
           for(int j=0;j<=n;j+=2)
           cout<<dp[i][j]<<" ";
           cout<<endl;
       }
       cout<<dp[l][n]%MOD<<endl;
   }
   return 0;
}