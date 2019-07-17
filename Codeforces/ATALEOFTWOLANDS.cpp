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

 ll bsearch(ll low,ll high,vector<ll>& arr,ll val){
   ll mid;
   if(low<=high){
     mid = (high + low)/2;
     if(val == arr[mid])
     return upper_bound(arr.begin(),arr.end(),val)-arr.begin()-1;
     if(val<arr[mid])
     high = mid-1;
     else
     low = mid+1;
     return bsearch(low,high,arr,val);
   }
   return low-1;
 }

 int main(){
 	FastIO
 	ll n;
  cin>>n;
  vi arr;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    arr.pb(abs(a));
  }
  sort(arr.begin(),arr.end());
  ll count=0;
  for(int i=0;i<arr.size();i++){
    ll x;
    x = arr[i];
    ll val = 2*x;
    count += bsearch(0,arr.size()-1,arr,val)-i;
  }
  cout<<count;
  // vector<int> arr = {-2,-1,-1,5,5,5,6,6,6,8,8};
  // cout<<bsearch(0,arr.size()-1,arr,0);
 	return 0;
 }
