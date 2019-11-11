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
void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl; }
int main(){
   FastIO
   ll n;
   cin>>n;
   vvi graph(n,vi(n));
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>graph[i][j];
       }
   }
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   reverse(v.begin(),v.end());
   vi res;
   vb add(n,false);
   for(int k=0;k<n;k++){
       ll sum=0;
       add[v[k]-1]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][v[k]-1]+graph[v[k]-1][j]<graph[i][j])
                graph[i][j] = graph[i][v[k]-1]+graph[v[k]-1][j];
                if(add[i] && add[j])
                sum+=graph[i][j];
            }
       }
        res.pb(sum);
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
   return 0;
}