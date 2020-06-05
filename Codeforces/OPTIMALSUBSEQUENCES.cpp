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

bool cmp(pair<ll,pii> a,pair<ll,pii> b){
    return a.ss.ff>b.ss.ff;
}

int main(){
   FastIO
   ll n;
   cin>>n;
   vi a(n);
   vpii temp(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
       temp[i].ff = -a[i];
       temp[i].ss = i;
   }
   sort(temp.begin(),temp.end());
   ll m;
   cin>>m;
   vector<pair<pii,ll > > res(m);
   for(int i=0;i<m;i++){
       cin>>res[i].ff.ff>>res[i].ff.ss;
       res[i].ss = i;
   }
   sort(res.begin(),res.end());
   ordered_set p;
   int len=0;
   vi ans(m);
   for(int i=0;i<m;i++){
       while(len<res[i].ff.ff)
       p.insert(temp[len++].ss);
       ans[res[i].ss] = a[*p.find_by_order(res[i].ff.ss-1)];
   }
   for(int i=0;i<m;i++)
   cout<<ans[i]<<endl;
   return 0;
}