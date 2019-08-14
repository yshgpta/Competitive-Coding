//ysh_gpta
#include<bits/stdc++.h>
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
ll gcd( ll a, ll b ){
   if(b==0){
        return a;
   }
   else{
        return gcd( b, a%b );
   }
}
int main(){
   FastIO
   int t;
   cin>>t;
   while(t--){
       int n,k;
       cin>>n>>k;
       vi v(n);
       for(int i=0;i<n;i++)
       cin>>v[i];
       int max_ele = *max_element(v.begin(),v.end());
       if(k>max_ele)
       max_ele = k;
       int m = pow(2,log2(max_ele)+1)-1;
       vvi dp(n+1,vi(1025,0));
       dp[0][0]=1;
       int max_val= k;
       for(int i=1;i<=n;i++){
           for(int j=0;j<=1023;j++){
               dp[i][j] = dp[i-1][j] | dp[i-1][j^v[i-1]];
           }
       }
       for(int j=0;j<=1023;j++){
           if(max_val<dp[n][j]*(j^k))
               max_val = dp[n][j]*(j^k);
       }
       cout<<max_val<<endl;
   }
   return 0;
}