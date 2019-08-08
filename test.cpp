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

vpii v;


 ll FindMaxSum(ll arr[], int n)
{
  ll maxSum = arr[0];
  ll maxSoFar = arr[0];
  ll tempBegin = 0;
  ll begin = 0;
  ll end = 0;
  for(int i=1;i<n;i++){
    maxSoFar += arr[i];
    if(maxSoFar<0){
      maxSoFar = 0;
      tempBegin = i+1;
    }else if(maxSoFar>maxSum){
      maxSum = maxSoFar;
      begin = tempBegin;
      end = i;
    }
  }
  for(int i=begin;i<=end;i++)
  v.pb(mp(-i,arr[i]));
  return maxSum;
}

 int main(){
 	FastIO
 	int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ll maxSum = FindMaxSum(arr,n);
    cout<<maxSum<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i].second;
    v.clear();
  }
 	return 0;
 }
