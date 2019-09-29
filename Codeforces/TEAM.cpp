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
   ll n,m;
   cin>>n>>m;
   if(m>=n-1 && m<=2*n+2){
       if(m==n-1){
           for(int i=0;i<m;i++){
                cout<<0<<1;
           }
           cout<<0;
       }else if(m==n){
           for(int i=0;i<n;i++){
               cout<<10;
           }
       }else if(m==n+1){
           for(int i=0;i<n;i++)
           cout<<10;
           cout<<1;
       }else{
           ll cnt = m-(n+1);
           for(int i=0;i<n;i++){
               if(cnt>0){
                   cout<<110;
                   cnt--;
               }else{
                   cout<<10;
               }
           }
           if(cnt>0)
            cout<<11;
            else
            cout<<1;
       }
   }
   else{
       cout<<-1;
   }
   return 0;
}