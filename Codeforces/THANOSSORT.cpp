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
vi arr;

ll solve(vi &arr,ll low,ll high){
  if(low==high)
  return 1;
  ll flag=0;
  for(int i=low;i<high;i++){
    if(arr[i]>arr[i+1]){
      flag=1;
      break;
    }
  }
  if(flag==0)
  return high-low+1;
  ll mid = (high+low)/2;
  return max(solve(arr,low,mid),solve(arr,mid+1,high));
}


int main(){
   FastIO
   cin>>n;
   for(int i=0;i<n;i++){
     ll a;
     cin>>a;
     arr.pb(a);
   }
   cout<<solve(arr,0,arr.size()-1);
   return 0;
}