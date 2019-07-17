#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 ll power(ll x, ll y, ll m)
 {
 ll res = 1;
 while(y>0){
   if(y&1)
   res = ((__int128)res*x)%m;
   y = y>>1;
   x = ((__int128)x*x)%m;
 }
 return res;
}

ll gcd( ll a, ll b ){
 	if(b==0)
 	  return a;
 	return gcd( b, a%b );
}


 int main(){
 	FastIO
 	int t;
  cin>>t;
  while(t--){
    ll a,b,n;
    cin>>a>>b>>n;
    if(a==b)
    cout<<(power(a,n,MOD) + power(b,n,MOD))%MOD<<endl;
    else{
      ll val=(power(a,n,a-b) + power(b,n,a-b))%(a-b);
      cout<<gcd(val,(a-b))%MOD<<endl;
    }
  }
 	return 0;
 }
