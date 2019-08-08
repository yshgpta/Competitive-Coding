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
 	int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vi arr1,arr2;
    ll count=0;
    for(int i=0;i<n;i++){
      ll a;
      cin>>a;
      if(a%3==0)
      count++;
      if(a%3==1)
      arr1.pb(a);
      if(a%3==2)
      arr2.pb(a);
    }
    ll val = min(arr1.size(),arr2.size());
    count += val;
    ll sz1 = arr1.size()-val;
    ll sz2 = arr2.size()-val;
    if(sz1>0)
    count+=(sz1/3);
    else if(sz2>0)
    count+=(sz2/3);
    cout<<count<<endl;
  }
 	return 0;
 }
