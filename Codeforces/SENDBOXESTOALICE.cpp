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

vi v;
ll n;

ll cost(ll p){
    ll res = 0;
    for(int i=0;i<v.size();i+=p){
        ll median = v[(i+i+p-1)/2];
        for(int j=i;j<i+p;j++){
            res += abs(v[j]-median);
        }
    }
    return res;
}

int main(){
   FastIO
   cin>>n;
   ll a;
   for(int i=1;i<=n;i++){
       cin>>a;
       if(a==1)
       v.pb(i);
   }
   if(v.size()==1){
       cout<<-1<<endl;
       return 0;
   }
   ll tmp = v.size();
   ll p=2;
   ll ans = 1e18;
   while(p*p<=tmp){
       if(tmp%p==0){
           ans = min(ans,cost(p));
           while(tmp%p==0)
           tmp/=p;
       }
       p++;
   }
   if(tmp>1){
       ans = min(ans,cost(tmp));
   }
   cout<<ans<<endl;
   return 0;
}