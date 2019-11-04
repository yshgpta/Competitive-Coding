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
   ll n;
   cin>>n;
   ll n7=0;
   ll n4=0;
   ll flag=0;
   if(n%4==0){
       ll temp = n/4;
       n7 = (temp/7)*4;
       n4 = temp%7;
   }else{
       if(n%2==1){
        n7++;
        n-=7;
        while(n%4!=0 && n>=0){
            n-=14;
            n7+=2;
        }
        if(n<0)
        flag=1;
        ll temp = n/4;
        n7 += (temp/7)*4;
        n4 += temp%7;
    }else{
        while(n%4!=0 && n>=0){
            n-=14;
            n7+=2;
        }
        if(n<0)
        flag=1;
        ll temp = n/4;
        n7 += (temp/7)*4;
        n4 += temp%7;
    }
   }
   if(flag==1){
       cout<<-1;
       return 0;
   }
   for(int i=0;i<n4;i++)
   cout<<4;
   for(int i=0;i<n7;i++)
   cout<<7;
   return 0;
}