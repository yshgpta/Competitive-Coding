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
   vi v(n+1);
   for(int i=1;i<=n;i++)
   cin>>v[i];
   vi sum(n+1,0);
   for(int i=1;i<=n;i++)
   sum[i] = v[i] + sum[i-1];
   if(sum[n]%3!=0){
       cout<<0;
       return 0;
   }
   ll val = sum[n]/3;
   vi ans;
   for(int i=1;i<=n-2;i++){
       if(sum[i]==val)
       ans.pb(i);
   }
   vi cnt(n+1,0);
   if(ans.size()==0){
       cout<<0;
       return 0;
   }
    ll j=ans[0]+1;
    while(j<n){
        if(sum[n]-sum[j]==val)
        cnt[j]=1;
        j++;
    }
   vi s(n+1,0);
   for(int i=1;i<=n;i++)
   s[i] = s[i-1]+cnt[i];
   ll count=0;
   for(int i=0;i<ans.size();i++){
       ll index = ans[i];
       ll j=index+1;
       count += s[n]-s[j-1];
   }
   cout<<count;
   return 0;
}