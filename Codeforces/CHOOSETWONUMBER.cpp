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
   int n;
   cin>>n;
   int max1 = INT_MIN;
   for(int i=0;i<n;i++){
       int a;
       cin>>a;
       if(max1<a)
       max1=a;
   }
   int m;
   cin>>m;
   int max2 = INT_MIN;
   for(int i=0;i<m;i++){
       int a;
       cin>>a;
       if(max2<a)
       max2=a;
   }
   cout<<max1<<" "<<max2;
   return 0;
}