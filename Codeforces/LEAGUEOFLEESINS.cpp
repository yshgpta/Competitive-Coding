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

ll findodd(vi v,ll a,ll b){
    for(int i=0;i<v.size();i++){
        if(v[i]!=a && v[i]!=b)
        return v[i];
    }
    return -1;
}


int main(){
   FastIO
   ll n;
   cin>>n;
   vvi v(n+1);
   vvi adj(n+1);
   for(int i=1;i<=n-2;i++){
       ll a,b,c;
       cin>>a>>b>>c;
       v[i].pb(a);
       v[i].pb(b);
       v[i].pb(c);
       adj[a].pb(i);
       adj[b].pb(i);
       adj[c].pb(i);
   }
   int index=-1;
   ll flag=1;
   vb vis(n-1,false);
   for(int i=1;i<=n-2;i++){
       if(adj[i].size()==1){
           index=i;
           break;
       }
   }
   vi res;
   ll x=-1,y=-1;
   ll initial;
   if(index==-1){
       cout<<-1;
       return 0;
   }
   else{
       res.pb(index);
       initial = adj[index][0];
       vi temp;
       for(int i=0;i<3;i++){
           if(v[initial][i]==index)
           continue;
           else
           temp.pb(v[initial][i]);
       }
       if(adj[temp[0]].size()<adj[temp[1]].size()){
           x = temp[0];
           y = temp[1];
       }else if(adj[temp[0]].size()>adj[temp[1]].size()){
           x = temp[1];
           y = temp[0];
       }
       if(x==-1 || y==-1){
       cout<<-1;
       cout<<"Hello2";
       return 0;
   }
   }
   ll z=1;
   res.pb(x);
   vis[initial]=true;
   while(z<n-2){
       res.pb(y);
       ll val=-1;
       int flg=0;
       for(int i=0;i<adj[x].size();i++){
           flg = 0;
           for(int j=0;j<adj[y].size();j++){
               if(adj[x][i]==adj[y][j] && !vis[adj[x][i]]){
                   val = adj[x][i];
                   vis[val]=true;
                   flg = 1;
                   break;
               }
           }
           if(flg == 1)
           break;
       }
       if(flg == 0){
       cout<<-1;
       return 0;
        }
       int t = y;
       y = findodd(v[val],x,y);
       x = t;
       if(y==-1){
       cout<<-1;
       return 0;
        }
       z++;
   }
   res.pb(y);
   for(int i=0;i<res.size();i++)
   cout<<res[i]<<" ";
   return 0;
}