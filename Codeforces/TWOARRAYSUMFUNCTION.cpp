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
 #define MOD 998244353
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



 int main(){
 	FastIO
 	ll n;
  cin>>n;
  vi arr(n),brr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  for(int i=0;i<n;i++)
  cin>>brr[i];
  vi val(n);
  for(int i=0;i<n;i++){
    val[i]=(i+1)*(n-i)*arr[i];
  }
  sort(brr.begin(),brr.end());
  sort(val.rbegin(),val.rend());
  ll ans=0;
  for(int i=0;i<n;i++){
    ans = (ans + (val[i]%MOD * brr[i])%MOD)%MOD;
  }
  cout<<ans;
 	return 0;
 }
