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
   ll q;
   cin>>q;
   while(q--){
       ll n,k;
       cin>>n>>k;
       string str;
       cin>>str;
       vi v;
       for(int i=0;i<n;i++){
           if(str[i]=='0')
           v.pb(i);
       }
       string res;
       ll limit=0;
       for(int i=0;i<v.size();i++){
           if(k-v[i]+limit>0){
               res = '0'+res;
               k=k - v[i] + limit;
               limit++;
           }
           else{
               for(int j=limit;j<v[i]-k;j++)
               res = res + '1';
               res = res + '0';
               for(int j=0;j<k;j++)
               res = res + '1';
            //    cout<<str.substr(v[i],n-v[i])<<endl;
               res = res + str.substr(v[i]+1,n-v[i]);
               break;
           }
       }
    //    while(res.length()<str.length())
    //    res = res + '1';
       cout<<res<<endl;
   }
   return 0;
}