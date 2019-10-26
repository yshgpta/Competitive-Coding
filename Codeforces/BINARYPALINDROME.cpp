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

pair<ll,pair<ll,ll> > count(string str){
    pair<ll,pair<ll,ll> > p;
    p.ff = str.length();
    ll ct=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0')
        ct++;
    }
    p.ss.ff = ct;
    p.ss.ff =  str.length()-ct;
    return p;
}

int main(){
   FastIO
   ll q;
   cin>>q;
   while(q--){
       ll n;
       cin>>n;
       vector<pair<ll,pair<ll,ll> > > v;
       for(int i=0;i<n;i++){
           string str;
           cin>>str;
           v.pb(count(str));
       }
       ll cnt=0;
       ll odd=0;
       ll lodd=0;
       for(int i=0;i<n;i++){
           if(v[i].ff%2==0 && v[i].ss.ff%2==0){
               cnt++;
           }
           else if(v[i].ff%2!=0){
               lodd++;
           }
           else if(v[i].ff%2==0 && v[i].ss.ff%2!=0){
               odd++;
           }
       }
       if(odd>0){
           if(odd%2==0)
           cnt+=odd;
           else{
               cnt+=(odd-1);
               if(lodd>0)
               cnt++;
           }
       }
       cnt+=lodd;
       cout<<cnt<<endl;
   }
   return 0;
}