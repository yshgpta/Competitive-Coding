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
int main(){
   FastIO
   ll a,b,c;
   cin>>a>>b>>c;
   ll x,y,z;
   cin>>x>>y>>z;
   ll sum=0;
   vi v(6);
   for(int i=0;i<6;i++){
       cin>>v[i];
       sum+=v[i];
   }
   if(a>=0 && a<=x)
   sum-=(v[4]+v[5]);
   else if(a>x)
   sum-=v[4];
   else 
   sum-=v[5];
   if(b>=0 && b<=y)
   sum-=(v[0]+v[1]);
   else if(b>y)
   sum-=v[0];
   else
   sum-=v[1];
   if(c>=0 && c<=z)
   sum-=(v[2]+v[3]);
   else if(c>z)
   sum-=v[2];
   else
   sum-=v[3];
   cout<<sum;
   return 0;
}