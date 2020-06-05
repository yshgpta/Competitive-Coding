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
       ll n,k;
       cin>>n>>k;
       ll j=0;
       for(int i=1;i<=k;i+=j){
           j++;
       }
       j--;
       ll last = j*(j+1)/2;
       ll v = k-last-1;
       j++;
       ll pos1 = pow(2,j);
       ll pos2 = pow(2,v);
    //    cout<<pos1<<" "<<pos2<<endl;
       ll pos = pos1+pos2;
    //    cout<<pos<<endl;
       string str;
       for(int i=n-1;i>=0;i--){
           if(i==j || i==v)
           str+='b';
           else
           str += 'a';
       }
       cout<<str<<endl;
   }
   return 0;
}