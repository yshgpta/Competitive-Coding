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

vi prefixArray(string str){
    ll n=str.size();
    vi p(n);
    p[0]=0;
    ll i=1;
    ll j=0;
    while(i<n){
        if(str[i]==str[j]){
            p[i]=j+1;
            i++;
            j++;
        }else{
            while(j!=0 && str[j]!=str[i]){
                j = p[j-1];
            }
            if(j==0 && str[j]!=str[i]){
                p[i]=0;
                i++;
            }
        }
    }
    return p;
}

int main(){
   FastIO
   string str;
   cin>>str;
   ll n = str.length();
   vi dp = prefixArray(str);
   ll flag=0;
   ll len;
   if(dp[n-1]!=0){
       for(int i=0;i<n-1;i++){
            if(dp[i]==dp[n-1]){
                len=dp[n-1];
                flag=1;
            }
       }
       if(flag==0){
           if(dp[dp[n-1]-1]!=0){
               len = dp[dp[n-1]-1];
               flag=1;
           }
       }
   }
   if(flag==0)
   cout<<"Just a legend";
   else
   cout<<str.substr(0,len);
   return 0;
}