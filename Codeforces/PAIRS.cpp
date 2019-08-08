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
 	ll n,m;
  cin>>n>>m;
  vpii arr;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    arr.pb(mp(a,b));
  }
  vi p1 = {arr[0].ff,arr[0].ss};
  for(auto c : p1){
    vi val(n+1,0);
    int cnt=0;
    for(auto pairs : arr){
      if(pairs.ff!=c && pairs.ss!=c){
        val[pairs.ff]++;
        val[pairs.ss]++;
        cnt++;
      }
    }
    if(*max_element(val.begin(),val.end())==cnt){
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
 	return 0;
 }
