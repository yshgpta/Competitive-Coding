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

vb visited(26,false);
vector<set<ll> > v(26);

void dfs(ll node){
    visited[node]=true;
    for(auto it : v[node]){
        if(!visited[it])
        dfs(it);
    }
    return;
}

int main(){
   FastIO
   ll n;
   cin>>n;
   while(n--){
       string str;
       cin>>str;
       char ch=str[0];
       for(int i=0;i<str.length();i++){
           v[ch-'a'].insert(str[i]-'a');
           v[str[i]-'a'].insert(ch-'a');
           ch = str[i];
       }
   }
   ll count=0;
   for(int i=0;i<26;i++){
       if(!visited[i] && v[i].size()!=0){
           count++;
           dfs(i);
       }
   }
   cout<<count;
   return 0;
}