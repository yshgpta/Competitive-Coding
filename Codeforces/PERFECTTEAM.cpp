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

ll solve(ll a,ll b){
    if(a==0 || b==0)
    return 0;
    if(a>=2*b)
    return b;
    else
    return (a+b)/3;
}

int main(){
   FastIO
   int t;
   cin>>t;
   while(t--){
       int c,m,x;
       cin>>c>>m>>x;
       ll ans=0;
       if(c==0 || m==0){
           cout<<0<<endl;
           continue;
       }
       if(x>=max(c,m)){
           if(c<m)
           cout<<c<<endl;
           else
           cout<<m<<endl;
           continue;
       }
       if(x<=min(c,m)){
           c-=x;
           m-=x;
           ans+=x;
           if(c>=m)
           ans += solve(c,m);
           else
           ans += solve(m,c);
           cout<<ans<<endl;
           continue;
       }
        cout<<min(c,min(m,x))<<endl;
   }
   return 0;
}