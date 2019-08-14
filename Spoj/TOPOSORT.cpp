//ysh_gpta
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll gcd( ll a, ll b ){
   if(b==0){
        return a;
   }
   else{
        return gcd( b, a%b );
   }
}
vi adj[10005];
int main(){
   FastIO
   ll n,m;
   cin>>n>>m;
   vi indegree(n+1,0);
   while(m--){
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       indegree[v]++;
   }
   priority_queue<ll,vector<ll>,greater<ll> >pq;
   for(int i=1;i<=n;i++)
   if(indegree[i]==0)
   pq.push(i);
   int count=0;
   vi ans;
   while(!pq.empty()){
       int u = pq.top();
       pq.pop();
       ans.pb(u);
       count++;
       for(int i=0;i<adj[u].size();i++){
           int v = adj[u][i];
           indegree[v]--;
           if(indegree[v]==0)
           pq.push(v);
       }
   }
   if(count==n){
       for(int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";
   }else{
       cout<<"Sandro fails.";
   }
   return 0;
}