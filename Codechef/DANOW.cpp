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



 int main(){
 	FastIO
 	int n,q;
  cin>>n>>q;
  vi arr,brr;
  ll a;
  arr.pb(0);
  brr.pb(0);
  for(int i=0;i<n;i++){
    cin>>a;
    arr.pb(a);
  }
  for(int i=0;i<n;i++){
    cin>>a;
    brr.pb(a);
  }
  for(int i=0;i<q;i++){
    ll l,r;
    cin>>l>>r;
    ll sum=0;
    for(int j=l;j<=r;j++){
      sum+=arr[j]*brr[j];
    }
    cout<<sum<<endl;
  }
 	return 0;
 }
