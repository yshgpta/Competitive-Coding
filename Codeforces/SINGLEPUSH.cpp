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
       vi a(n),b(n);
       for(int i=0;i<n;i++)
       cin>>a[i];
       for(int j=0;j<n;j++)
       cin>>b[j];
       ll i=0;
       ll flag=0;
       while(i<n && b[i]-a[i]==0)
       i++;
       ll diff;
       if(i!=n){
            diff = b[i]-a[i];
            if(diff<0)
            flag=1;
       }
       while(flag==0 && i<n && diff==b[i]-a[i])
       i++;
       while(flag==0 && i<n){
           if(b[i]-a[i]!=0){
               flag=1;
               break;
           }
           i++;
       }
       if(flag==0)
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl;
   }
   return 0;
}