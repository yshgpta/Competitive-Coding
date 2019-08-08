//ysh_gpta
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define vpii vector<pair<ll,ll> >
 #define mp make_pair
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 ll gcd( ll a, ll b )
 {
 	if(b==0)
 	{
 	     return a;
 	}
 	else
 	{
 	     return gcd( b, a%b );
 	}
 }
 ll lcm (ll a, ll b)
 {
 	return (a*b)/gcd(a,b);
 }


 int main(){
 	FastIO
 	ll a,b;
  cin>>a>>b;
  ll temp = abs(a-b);
  ll 
  cout<<k;
 	return 0;
 }
