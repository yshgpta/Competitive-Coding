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
   string arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   while(t--){
       ll r,c,k;
       cin>>r>>c>>k;
       vector<string> v(r);
       ll rcnt=0;
       for(int i=0;i<r;i++){
           cin>>v[i];
           for(int j=0;j<c;j++){
               if(v[i][j]=='R')
               rcnt++;
           }
       }
       ll val = rcnt/k;
       vi a(k,val);
       ll excess = rcnt%k;
       ll z=0;
       while(excess!=0){
           a[z++]++;
           excess--;
       }
       z=0;
       ll count=0;
       vector<vector<char> > res(r,vector<char>(c));
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(v[i][j]=='R'){
                   count++;
                   res[i][j] = arr[z];
                   if(count==a[z]){
                       count=0;
                       if(z<k-1)
                       z++;
                   }
               }else{
                   res[i][j] = arr[z];
               }
           }
           if(i<r-1){
               i++;
               for(int j=c-1;j>=0;j--){
                    if(v[i][j]=='R'){
                        count++;
                        res[i][j] = arr[z];
                        if(count==a[z]){
                            count=0;
                            if(z<k-1)
                            z++;
                        }
                    }else{
                        res[i][j] = arr[z];
                    }
                }
           }
       }
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++)
           cout<<res[i][j];
           cout<<endl;
       }
   }
   return 0;
}