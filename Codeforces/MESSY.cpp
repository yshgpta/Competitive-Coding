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
   char arr[] = {'(',')'};
   while(t--){
       ll n,k;
       cin>>n>>k;
       string s;
       cin>>s;
       ll len = (k-1)*2;
       vpii res;
       for(int i=0;i<len;i++){
           char ch = s[i];
           if(ch==arr[i%2])
           continue;
           ll j=i;
           while(s[j]!=arr[i%2] && j<n)
           j++;
           res.pb(mkp(i+1,j+1));
           reverse(s.begin()+i,s.end()-n+j+1);
       }
       ll i=len;
       ll val = (n-len)/2;
       for(int i=len;i<val+len;i++){
           if(s[i]=='(')
           continue;
           ll j=i;
           while(s[j]!='(' && j<n)
           j++;
           res.pb(mkp(i+1,j+1));
           reverse(s.begin()+i,s.end()-n+j+1);
       }
       cout<<res.size()<<endl;
       for(int i=0;i<res.size();i++)
       cout<<res[i].ff<<" "<<res[i].ss<<endl;
    //    cout<<s<<endl;
   }
   return 0;
}