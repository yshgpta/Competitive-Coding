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
       ll n,k;
       cin>>n>>k;
       vi v(n);
       for(int i=0;i<n;i++)
       cin>>v[i];
       bool even=false;
       if(n%2==0)
       even=true;
       vvi arr(n,vi(3,0));
       for(int i=0;i<n/2;i++){
           arr[i][0]=v[i]^v[n-i-1];
           arr[i][1]=v[n-i-1];
           arr[i][2]=v[i];
           arr[n-1-i][0]=v[i];
           arr[n-1-i][1]=v[i]^v[n-i-1];
           arr[n-1-i][2]=v[n-i-1];
       }
       vi b(n);
       for(int i=0;i<n;i++){
           b[i] = (k-1+n-i)/n - 1;
       }
       vi res(n);
       for(int i=0;i<n;i++){
           res[i] = arr[i][b[i]%3];
       }
       for(int i=0;i<n;i++)
       cout<<res[i]<<" ";
       cout<<endl;
   }  
   return 0;
}