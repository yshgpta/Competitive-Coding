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
int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n;
       cin>>n;
       vector<queue<ll> > v(n);
       for(int i=0;i<n;i++){
           ll a;
           cin>>a;
           for(int j=0;j<a;j++){
               ll b;
               cin>>b;
               v[i].push(b);
           }
       }
       vb vis(n+1,false);
       ll idx = -1;
       ll cnt =0;
       ll flag=0;
       for(int i=0;i<n;i++){
           if(v[i].empty() && flag==0){
               idx = i+1;
               flag=1;
           }
           else if(!v[i].empty() && vis[v[i].front()]){
               while(!v[i].empty() && vis[v[i].front()]){
                //    cout<<v[i].front()<<endl;
                   v[i].pop();
               }
               if(v[i].empty()){
                   idx = i+1;
                //    cout<<"idx"<<idx<<endl;
               }else{
                   vis[v[i].front()]=true;
                    v[i].pop();
                    cnt++;
               }
           }else if(!v[i].empty() && !vis[v[i].front()]){
            //    cout<<v[i].front()<<endl;
               vis[v[i].front()]=true;
               v[i].pop();
               cnt++;
           }
       }
       if(cnt==n){
           cout<<"OPTIMAL"<<endl;
       }else{
           ll val;
           for(int i=1;i<=n;i++){
               if(!vis[i]){
                   val = i;
                   break;
               }
           }
        //    cout<<"cnt"<<cnt<<endl;
           cout<<"IMPROVE"<<endl;
           cout<<idx<<" "<<val<<endl;
       }
   }
   return 0;
}