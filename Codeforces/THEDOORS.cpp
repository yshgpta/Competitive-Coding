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
 	ll n;
  cin>>n;
  vi arr(n);
  ll cnt1=0,cnt0=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==0)
    cnt0++;
    else
    cnt1++;
  }
  ll count=0;
  for(int i=0;i<n;i++){
    if(cnt0==0 || cnt1==0){
      cout<<count;
      return 0;
    }
    count++;
    if(arr[i]==0)
    cnt0--;
    else
    cnt1--;
  }
 	return 0;
 }
