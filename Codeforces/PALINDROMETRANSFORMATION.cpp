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
   ll n,p;
   cin>>n>>p;
   string str;
   cin>>str;
   ll count=0;
   vi v;
   ll start=0;
   ll limit=n/2;
   if(p>n/2){
       start=n/2;
       limit = n;
   }
   for(int i=start;i<limit;i++){
       if(str[i]>str[n-1-i]){
           count+=min(str[i]-str[n-1-i],26-str[i]+str[n-1-i]);
           v.pb(i);
       }else if(str[i]<str[n-1-i]){
           count+=min(str[n-1-i]-str[i],26-str[n-1-i]+str[i]);
           v.pb(i);
       }
   }
   if(v.size()==0){
       cout<<count;
       return 0;
   }
   sort(v.begin(),v.end());
   ll len = v.size();
   p--;
//    cout<<p<<endl;
   if(p<v[0])
   count+=v[len-1]-p;
   else if(p>v[len-1])
   count+=p-v[0];
   else{
       if(p-v[0]<v[len-1]-p){
           count+=v[len-1]-p;
           count+=2*(p-v[0]);
       }else{
           count+=2*(v[len-1]-p);
           count+=p-v[0];
       }
   }
   cout<<count;
   return 0;
}