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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<
//; cout<<endl; }
int main(){
   FastIO
   string str;
   cin>>str;
   string res;
   ll flag=0;
   for(int i=0;i<str.length();i++){
       if(str[i]-'0'>1){
           res = '1' + res;
           flag=1;
       }
       else if(str[i]-'0'==1){
           res = '1' + res;
       }
       else if(str[i]-'0'==0){
           if(flag==1){
               res = '1' + res;
           }else{
               res = '0' + res;
           }
       }
   }
//    cout<<res<<endl;
//    reverse(res.begin(),res.end());
   ll count=0;
   for(int i=0;i<res.length();i++){
       count += (res[i]-'0')*pow(2,i);
   }
   cout<<count;

   return 0;
}