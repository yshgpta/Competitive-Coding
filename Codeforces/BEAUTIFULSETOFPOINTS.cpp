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
   ll n,m;
   cin>>n>>m;
   if(n==1 && m==1){
       cout<<2<<endl;
       cout<<0<<" "<<1<<endl;
       cout<<1<<" "<<0<<endl;
       return 0;
   }
   vpii v;
   if(m<n){
       ll i=0;
       while(i<=m){
           v.pb(mkp(i+1,i));
           i++;
       }
   }else if(n<m){
       ll i=0;;
       while(i<=n){
           v.pb(mkp(i,i+1));
           i++;
       }
   }else{
       ll i=0;
       while(i<=n){
           v.pb(mkp(n-i,i));
           i++;
       }
   }
   cout<<v.size()<<endl;
   for(int i=0;i<v.size();i++)
   cout<<v[i].ff<<" "<<v[i].ss<<endl;
   return 0;
}