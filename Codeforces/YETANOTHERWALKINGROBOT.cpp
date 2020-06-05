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
       string str;
       map<pii,ll> mp;
       cin>>str;
       ll i=0;
       ll j=0;
       ll len=INT_MAX;
       ll si,ei;
       mp[mkp(i,j)] = 0;
       for(int idx = 0;idx<str.length();idx++){
           if(str[idx]=='L') i--;
           else if(str[idx]=='R') i++;
           else if(str[idx]=='U') j++;
           else j--;
           
           if(mp.find(mkp(i,j))==mp.end()){
               mp[mkp(i,j)] = idx+1;
           }else{
               ll l = (idx+1) - mp[mkp(i,j)];
            //    cout<<l<<endl;
               if(l<len){
                   len = l;
                   si = mp[mkp(i,j)]+1;
                   ei = idx+1;
               }
               mp[mkp(i,j)] = idx+1;
           }
        //    cout<<i<<" "<<j<<" "<<mp[mkp(i,j)]<<endl; 
       }
       if(len==INT_MAX)
       cout<<-1<<endl;
       else{
           cout<<si<<" "<<ei<<endl;
       }
   }
   return 0;
}