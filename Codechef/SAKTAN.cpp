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
int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n,m,q;
       cin>>n>>m>>q;
       vi x(n+1,0);
       vi y(m+1,0);
       while(q--){
           ll a,b;
           cin>>a>>b;
           x[a]++;
           y[b]++;
       }
       ll nodd_x = 0,neven_x=0,nodd_y=0,neven_y=0;
       for(int i=1;i<=n;i++){
            if(x[i]%2==0)
            neven_x++;
            else
            nodd_x++;
       }
       for(int i=1;i<=m;i++){
            if(y[i]%2==0)
            neven_y++;
            else
            nodd_y++;
       }
       cout<<(neven_x*nodd_y) + (nodd_x*neven_y)<<endl;
   }
   return 0;
}