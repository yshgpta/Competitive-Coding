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



 int main(){
 	FastIO
 	int t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    vi arr(n+1);
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    int i;
    int position=0;
    ll prev_sum=0;
    for(i=1;i<=n;i++){
      double d=1;
      ll sum =0;
      for(int j=i;j<=n;j++){
        sum += ceil(arr[j]/d);
        d++;
        if(sum>k)
        break;
      }
      if(sum<=k && prev_sum<=sum){
        prev_sum = sum;
        position = i;
        break;
      }
    }
    if(position==0)
    position=n+1;
    cout<<position<<endl;
  }
 	return 0;
 }
