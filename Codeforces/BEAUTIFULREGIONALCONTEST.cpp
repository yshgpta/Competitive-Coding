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
       vi v(n);
       map<ll,ll> mp;
       for(int i=0;i<n;i++){
           cin>>v[i];
       }
       for(int i=0;i<n/2;i++){
           mp[v[i]]++;
       }
       if(mp.size()<3){
           cout<<0<<" "<<0<<" "<<0<<endl;
           continue;
       }
       if(v[n/2]==v[n/2-1]){
           mp[v[n/2-1]]=0;
       }
       auto itr = mp.rbegin();
       ll gc = itr->ss;
       ll gv = itr->ff;
       itr++;
       ll sc = 0;
       ll flag=0;
       for(;itr!=mp.rend();itr++){
           sc += itr->ss;
           if(sc>gc){
               flag=1;
               itr++;
               break;
           }
       }
       bool impossible = false;
       if(flag==0){
           impossible = true;
       }
       ll bc = 0;
       flag=0;
       for(;itr!=mp.rend();itr++){
        //    cout<<bc<<" "<<itr->ff<<" "<<itr->ss<<endl;
           bc += itr->ss;
       }
       if(bc<=gc)
       impossible = true;
       if(!impossible)
       cout<<gc<<" "<<sc<<" "<<bc<<endl;
       else
       cout<<0<<" "<<0<<" "<<0<<endl;
    //    for(auto itr = mp.rbegin();itr!=mp.rend();itr++)
    //    cout<<itr->ff<<" "<<itr->ss<<endl;
   }
   return 0;
}