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
   ll n,k;
   cin>>n>>k;
   deque<ll> dq;
   ll j=1;
   map<ll,bool> mp;
   while(j<=n){
       ll a;
       cin>>a;
       j++;
       if(mp.find(a)==mp.end())
       mp[a]=false;
       if(dq.size()<k && mp[a]==false){
           dq.push_front(a);
           mp[a]=true;
       }
        else if(dq.size()==k && mp[a]==false){
            ll back = dq.back();
            mp[back] = false;
            dq.pop_back();
            dq.push_front(a);
            mp[a]=true;
        }
   }
       cout<<dq.size()<<endl;
       for(auto it = dq.begin();it!=dq.end();it++){
           cout<<*it<<" ";
       }
   return 0;
}