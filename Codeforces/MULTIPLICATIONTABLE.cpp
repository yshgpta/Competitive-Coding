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
ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
int main(){
   FastIO
   ll n;
   cin>>n;
   vvi v;
   ll a;
   vi ans;
   for(int i=0;i<n;i++){
       vi arr;
       for(int j=0;j<n;j++){
           cin>>a;
           arr.pb(a);
       }
       v.pb(arr);
   }
   ll res = v[n-1][0];
   for(int j=1;j<n-1;j++){
       res = gcd(res,v[n-1][j]);
   }
   ans.pb(res);
   for(int i=n-2;i>=0;i--){
       ans.pb(v[n-1][i]/res);
   }
   reverse(ans.begin(),ans.end());
//    for(int i=1;i<n;i++){
//        res = v[i][0];
//        for(int j=0;j<n;j++){
//            res = gcd(res,v[i][j]);
//        }
//        ans.pb(res);
//        if(ans[0]!=(v[i][0]/res))
//        ans[0]=v[i][0]/res;
//    }
   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";
   return 0;
}