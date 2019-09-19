//ysh_gpta
#include<bits/stdc++.h>
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
   string str;
   cin>>str;
   ll zero=0;
   ll one =0;
   for(int i=0;i<n;i++){
       if(str[i]=='z')
       zero++;
       if(str[i]=='n')
       one++;
   }
   while(one--)
    cout<<1<<" ";
   while(zero--)
   cout<<0<<" ";
   return 0;
}