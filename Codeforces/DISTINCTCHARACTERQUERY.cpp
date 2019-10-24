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
ordered_set ost[26];
int main(){
   FastIO
   string str;
   cin>>str;
   vi arr(str.length());
   for(int i=0;i<str.length();i++){
       arr[i] = str[i]-'a';
       ost[arr[i]].insert(i);
   }
   ll q;
   cin>>q;
   while(q--){
       ll qt;
       cin>>qt;
       if(qt==1){
           char ch;
           ll i;
           cin>>i>>ch;
           i--;
           ll j=arr[i];
           arr[i] = ch-'a';
           ost[j].erase(i);
           ost[arr[i]].insert(i);
       }else{
           ll l,r;
           cin>>l>>r;
           l--;r--;
           ll ans=0;
           for(int i=0;i<=25;i++){
               ll j=ost[i].order_of_key(r+1)-ost[i].order_of_key(l);
               if(j)
               ans++;
               
           }
           cout<<ans<<endl;
       }
   }
   return 0;
}