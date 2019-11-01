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
       ll n;
       cin>>n;
       string str1,str2;
       cin>>str1;
       cin>>str2;
       int flag=1;
       bool ispossible = true;
       for(int i=0;i<n;i++){
           if(flag==1){
               if(str1[i] -'0'<=2)
               continue;
               else{
                   flag=2;
                   if(str2[i]-'0'<=2){
                       ispossible=false;
                       break;
                   }
               }
           }else{
               if(str2[i]-'0'<=2)
               continue;
               else{
                   flag=1;
                   if(str1[i]-'0'<=2){
                       ispossible=false;
                       break;
                   }
               }
           }
       }
       if(flag==1)
       ispossible=false;
    if(ispossible)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
   }
   return 0;
}