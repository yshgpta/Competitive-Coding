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

ll n;
ll a[2];
vpii res(2);
vi d1(4005,0);
vi d2(4005,0);
ll arr[2005][2005];

void solve(ll c,ll i,ll j,ll val){
    if(val>a[c]){
        a[c]=val;
        res[c].ff = i;
        res[c].ss = j;
    }
}

int main(){
   FastIO
   cin>>n;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           cin>>arr[i][j];
           d1[i+j] += arr[i][j];
           d2[i-j+n] += arr[i][j]; 
       }
   }
   a[0]=a[1]=-1;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           solve((i+j)&1,i,j,d1[i+j]+d2[i-j+n]-arr[i][j]);
       }
   }
   cout<<a[0]+a[1]<<endl;
   cout<<res[0].ff<<" "<<res[0].ss<<" "<<res[1].ff<<" "<<res[1].ss;
   return 0;
}