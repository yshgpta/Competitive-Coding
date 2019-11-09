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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<
//; cout<<endl; }

bool check(string s,ll k){
    for(int i=0;i<s.length();i++){
        if(s[i%k]!=s[i])
        return false;
    }
    return true;
}

int main(){
   FastIO
   string s1,s2;
   cin>>s1>>s2;
   ll l1 = s1.length();
   ll l2 = s2.length();
   ll cnt=0;
   for(int i=1;i<=min(l1,l2);i++){
       if(l1%i==0 && l2%i==0){
           if(s1.substr(0,i)==s2.substr(0,i)){
               if(check(s1,i) && check(s2,i))
               cnt++;
           }
       }
   }
   cout<<cnt;
   return 0;
}