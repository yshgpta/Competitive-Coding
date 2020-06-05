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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<endl; cout<<endl; }
int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n,m;
       cin>>n>>m;
       string str;
       cin>>str;
       vi v(m);
       for(int i=0;i<m;i++)
       cin>>v[i];
       sort(v.begin(),v.end());
       vi res(26);
       ll j=0;
       for(int i=0;i<str.length();i++){
           res[str[i]-'a']++;
       }
       ll a = 0;
       for(int i=0;i<m;i++){
           ll count=m-i;
           ll len = v[i]-a;
           ll j = len+a;
           for(int k=a;k<j;k++){
               res[str[k]-'a']+=count;
           }
           a=v[i];
       }
       for(int i=0;i<26;i++){
           cout<<res[i]<<" ";
       }
       cout<<endl;
   }
   return 0;
}