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
int main(){
   FastIO
   string str;
   cin>>str;
   int i=0;
   string s;
   string temp;
   int flag;
   vector<pair<char,ll> > v;
    while(i<str.length()){
        ll count=1;
        while(i<str.length() && str[i]==str[i+1]){
            count++;
            i++;
        }
        temp+=str[i]+to_string(count);
        v.pb(mkp(str[i],count));
        i++;
    }
// cout<<temp<<endl;
   i=0;
   flag=0;
   while(i<v.size()){
       char ch = v[i].ff;
       ll count = v[i].ss;
       if(count>=2 && flag==0){
           s+=ch;
           s+=ch;
           flag=1;
       }else if(count>=2 && flag==1){
           s+=ch;
           flag=0;
       }else{
           s+=ch;
           flag=0;
       }
       i++;
   }
   cout<<s;
   return 0;
}