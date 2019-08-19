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
ll gcd( ll a, ll b ){
   if(b==0){
        return a;
   }
   else{
        return gcd( b, a%b );
   }
}
vector<vector<ll> > dp(10005,vector<ll>(10005,-1));


int main(){
   FastIO
   ll n,X,Y;
   cin>>n>>X>>Y;
   vi arr,brr;
   for(int i=0;i<n;i++){
       int a;
       cin>>a;
       arr.pb(a);
   }
   for(int i=0;i<n;i++){
       int a;
       cin>>a;
       brr.pb(a);
   }
   vector<pair<ll,pair<ll,ll> > > v;
   for(int i=0;i<n;i++){
       v.pb(mkp(abs(arr[i]-brr[i]),mkp(arr[i],brr[i])));
   }
   sort(v.begin(),v.end(),greater<pair<ll,pair<ll,ll> > >());
   ll count=0;
   ll andycnt=0,bobcnt=0;
   for(int i=0;i<n;i++){
       ll a = v[i].ss.ff;
       ll b = v[i].ss.ss;
       if(a>b){
           if(andycnt+1<=X){
               andycnt++;
               count += a;
           }else{
               bobcnt++;
               count += b;
           }
       }else{
           if(bobcnt+1<=Y){
               bobcnt++;
               count += b;
           }else{
               andycnt++;
               count += a;
           }
       }
   }
   cout<<count;
   return 0;
}