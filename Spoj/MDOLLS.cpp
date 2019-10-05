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
   int t;
   cin>>t;
   while(t--){
       ll n;
       cin>>n;
       vpii arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i].ff;
           cin>>arr[i].ss;
       }
       sort(arr.begin(),arr.end(),greater<int>());
       vpii tail(n);
       tail[0] = arr[0];
       int j=1;
       ll count=0;
       for(int i=0;i<n;i++){
           if(arr[i].ff < tail[0].ff && arr[i].ss > tail[0].ss){
               count++;
               tail[0]=arr[i];
           }else if(arr[i].ff < tail[0].ff && arr[i].ss < tail[0].ss){
               tail[j++] = arr[i];
           }
       }
   }
   return 0;
}