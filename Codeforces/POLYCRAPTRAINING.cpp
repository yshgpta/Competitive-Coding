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



 int main(){
 	FastIO
 	ll n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  sort(arr.begin(),arr.end());
  ll k=1;
  ll count=0;
  for(int i=0;i<n;i++){
    if(arr[i]>=k)
    count++;
    if(arr[i]==k){
      while(arr[i]==k)
      i++;
      i--;
    }
    k++;
  }
  cout<<count;
 	return 0;
 }
