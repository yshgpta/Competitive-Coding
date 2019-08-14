//ysh_gpta
#include<bits/stdc++.h>
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
ll gcd( ll a, ll b ){
   if(b==0){
        return a;
   }
   else{
        return gcd( b, a%b );
   }
}
int main(){
   FastIO
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       string str;
       vvi dp1(n,vi(n,0));
       vvi dp2(n,vi(n,0));
       vector<string> v;
       for(int i=0;i<n;i++){
           string str;
           cin>>str;
           v.pb(str);
       }
       for(int i=0;i<n;i++){
           string s = v[i];
           for(int j=n-1;j>=0;j--){
               if(s[j]=='.')
               dp1[i][j]=1;
               else
               break;
           }
       }
       for(int i=0;i<n;i++){
           for(int j=n-1;j>=0;j--){
               if(v[j][i] == '.')
               dp2[j][i]=1;
               else
               break;
           }
       }
       int count=0;
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       if(dp1[i][j] && dp2[i][j])
       count++;
       cout<<count<<endl;
   }
   return 0;
}