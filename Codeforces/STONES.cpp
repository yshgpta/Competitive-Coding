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
       ll a,b,c;
       cin>>a>>b>>c;
       ll count=0;
       if(b>=c/2){
           count+=((c/2)*2)+c/2;
           b-=c/2;
           c=0;
        //    cout<<count<<endl;
        //    cout<<b<<endl;
       }else{
           count+=2*b+b;
           c-=2*b;
           b=0;
       }
       if(b!=0){
           if(a>=b/2){
               count+=(b/2)*2+b/2;
               a-=b/2;
               b=0;
            //    cout<<count<<endl;
           }else{
               count+=2*a+a;
               b-=2*a;
               a=0;
           }
       }
       cout<<count<<endl;
   }
   return 0;
}