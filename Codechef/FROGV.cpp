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
   ll n,p,k;
   cin>>n>>k>>p;
   vpii arr;
   for(int i=0;i<n;i++){
       ll a;
       cin>>a;
       arr.pb(mkp(a,i));
   }
   sort(arr.begin(),arr.end());
   vi dp(n,0);
   dp[arr[n-1].ss] = arr[n-1].ff + k;
   for(int i=n-2;i>=0;i--){
       if((arr[i+1].ff-arr[i].ff) <=k)
       dp[arr[i].ss] = dp[arr[i+1].ss];
       else
       dp[arr[i].ss] = arr[i].ff + k;
   }
   for(int i=0;i<p;i++){
       int a,b;
       cin>>a>>b;
       a--;
       b--;
       if(dp[a]==dp[b])
       cout<<"Yes"<<endl;
       else
       cout<<"No"<<endl;
   }
//    for(int i=0;i<n;i++)
//    cout<<dp[i]<<" ";
   return 0;
}