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
   string str1,str2;
   cin>>str1>>str2;
   ll n1 = str1.length();
   ll n2 = str2.length();
   ll dp[n1+1][n2+1];
   for(int i=0;i<=n1;i++){
       for(int j=0;j<=n2;j++){
           if(i==0 || j==0)
           dp[i][j]=0;
           else if(str1[i-1]==str2[j-1])
           dp[i][j] = 1 + dp[i-1][j-1];
           else
           dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
       }
   }
   string str;
   ll i=n1,j=n2;
   while(i>0 && j>0){
       if(str1[i-1]==str2[j-1]){
           str = str1[i-1] + str;
           i--;
           j--;
       }else{
           if(dp[i-1][j]>dp[i][j-1]){
               i--;
           }else{
               j--;
           }
       }
   }
   cout<<str;
   return 0;
}