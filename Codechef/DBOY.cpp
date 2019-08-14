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

ll n;

int main(){
   FastIO
   int t;
   cin>>t;
   while(t--){
       cin>>n;
       vi v;
       vi arr;
       for(int i=0;i<n;i++){
           int a;
           cin>>a;
           v.pb(a*2);
       }
       for(int i=0;i<n;i++){
           int a;
           cin>>a;
           arr.pb(a);
       }
       sort(arr.begin(),arr.end());
       ll val = *max_element(v.begin(),v.end());
        vi dp(val+1,0);
        for(int i=1;i<=val;i++)
        dp[i] = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=arr[i];j<=val;j++){
                dp[j] = min(dp[j],dp[j-arr[i]]+1);
            }
        }
       ll ans = 0;
       for(int i=0;i<n;i++){
           ans += dp[v[i]];
       }
       cout<<ans<<endl;
   }
   return 0;
}