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
//ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
int main(){
   FastIO
   ll n;
   cin>>n;
   vpii v;
   for(int i=0;i<n;i++){
       ll a,b;
       cin>>a>>b;
       v.pb(mkp(a,b));
   }
   sort(v.begin(),v.end());
   ll flag=0;
   ll b = -1;
   for(int i=0;i<n;i++){
       if(b<=v[i].ss)
       b=v[i].ss;
       else
       b=v[i].ff;
   }
   cout<<b;
   return 0;
}