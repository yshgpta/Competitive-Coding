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
       ll n;
       cin>>n;
       vi v;
       map<ll,vpii> mp;
       while(n--){
           ll a,b,c;
           cin>>a>>b>>c;
           mp[c].pb(mkp(a,b));
       }
       for(auto &it:mp){
           sort(it.second.begin(),it.second.end());
       }
       ll flag=0;
       for(auto &it:mp){
           vpii v = it.second;
           if(v.size()<=2)
           continue;
           for(int i=0;i<v.size();i++){
               ll l = v[i].ff;
               ll r = v[i].ss;
               for(int j=i+1;j<v.size();j++){
                   ll maxl = max(l,v[j].ff);
                   ll minr = min(r,v[j].ss);
                   flag=0;
                   if(maxl<=minr){
                       for(int k=j+1;k<v.size();k++){
                           if(minr>=v[k].ff && maxl<=v[k].ss){
                               flag=1;
                               break;
                           }
                       }
                       if(flag==1)
                       break;
                   }
               }
               if(flag==1)
               break;
           }
           if(flag==1)
           break;
       }
       if(flag==1)
       cout<<"NO"<<endl;
       else
       cout<<"YES"<<endl;
   }
   return 0;
}