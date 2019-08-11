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
int main(){
   FastIO
   int tc;
   cin>>tc;
   while(tc--){
       priority_queue<pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > > pq;
       ll n,m,s,e;
       cin>>n>>m>>s>>e;
       vi time(n+1,INT_MAX);
       vector<bool> visited(n+1,false);
       time[s]=0;
       vpii adj[n+1];
       while(m--){
           int c1,c2,t;
           cin>>c1>>c2>>t;
           adj[c1].pb(mkp(c2,t));
           adj[c2].pb(mkp(c1,t));
       }
       pq.push(mkp(0,s));
       int flag=0;
       while(!pq.empty()){
           pii tp = pq.top();
           pq.pop();
           int u = tp.ss;
           if(visited[u])
           continue;
           for(int i=0;i<adj[u].size();i++){
               int v = adj[u][i].ff;
               int t = adj[u][i].ss;
               if(!visited[v] && time[v]>=time[u]+t){
                   time[v] = time[u]+t;
                   pq.push(mkp(time[v],v));
               }
           }
           visited[u] = true;
           if(u==e){
               cout<<time[u]<<endl;
               flag=1;
               break;
           }
           
       }
       if(flag==0)
       cout<<"NONE"<<endl;
   }
   return 0;
}   