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
   ll n,m;
   cin>>n>>m;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   sort(v.begin(),v.end());
   vi sum(n,0);
   sum[0]=v[0];
   for(int i=1;i<n;i++)
   sum[i] = sum[i-1] + v[i];
   vi res(n);
   ll k=0;
   while(k<m){
       res[k]=sum[k];
       k++;
   }
   for(int i=m;i<n;i++){
       res[i] = res[i-m] + sum[i-m] + sum[i]-sum[i-m];
   }
   for(int i=0;i<res.size();i++)
   cout<<res[i]<<" ";

   return 0;
}