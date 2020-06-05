//ysh_gpta
#include<bits/stdc++.h>
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
   ll t;
   cin>>t;
   for(int i=1;i<=t;i++){
       int n,s;
       cin>>n>>s;
       vvi v(s+1);
       map<ll,vi> mp;
       for(int j=1;j<=n;j++){
           int a;
           cin>>a;
           vi arr(a);
           for(int k=0;k<a;k++){
               cin>>arr[k];
               v[arr[k]].pb(j);
           }
           mp[j]=arr;
       }
       ll count=0;
        for(int j=1;j<=n;j++){
            vi vis(n+1,0);
            for(int k=0;k<=s;k++){
                if(find(v[k].begin(),v[k].end(),j)==v[k].end()){
                    for(int l=0;l<v[k].size();l++){
                        if(vis[v[k][l]]==0){
                            count++;
                            vis[v[k][l]]=1;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;
   }
   return 0;
}