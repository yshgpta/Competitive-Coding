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
map<ll,ll> mpx;
map<ll,ll> mp;
map<ll,ll> mpval;
ll n,m;
ll solve(vi &v,ll val){
    ll res = 0;
    if(mpx[val]==1||mpx[val]==n){
        if(mpx[val]==1){
            res += abs(mpval[v[1]]-mpval[v[2]]);
        }else{
            res += abs(mpval[v[n-1]]-mpval[v[n]]);
        }
    }else{
        ll index= mpx[val];
        res += abs(mpval[v[index-1]]-mpval[v[index]]) + abs(mpval[v[index]]-mpval[v[index+1]]);
    }
    return res;
}

int main(){
   FastIO
   cin>>n>>m;
   vi v(m);
   
   for(int i=1;i<=m;i++){
       cin>>v[i];
       mpx[v[i]]=i;
   }
   
   for(int i=1;i<=n;i++){
   mp[i]=i;
   mpval[i]=i;
   }
   vi res;
   ll sum = 0;
   for(int i=1;i<m;i++){
       sum += abs(v[mp[i]]-v[mp[i+1]]);
   }
   res.pb(sum);
   ll j=2;
//    while(j<=2){
//        ll val1 = mp[1];
//        ll valj = mp[j];
//        ll old_val= solve(v,val1) + solve(v,valj);
//        mp[j] = val1;
//        mp[1] = valj;
//        val1 = mp[1];
//        valj = mp[j];
//        mpval[val1]=1;
//        mpval[valj]=j;     
//        ll new_val = solve(v,val1) + solve(v,valj);
//        ll total = new_val - old_val;
//        sum += total;
//        res.pb(sum);
//        j++;
//    }
   for(int i=0;i<res.size();i++)
   cout<<res[i]<<" ";
   return 0;
}