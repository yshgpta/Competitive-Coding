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
  ll val=INT_MAX;
  vi hash(6,0);
  int index = 0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a==4){
      hash[0]++;
      index=0;
    }
    if(a==8)
    index=1;
    if(a==15)
    index=2;
    if(a==16)
    index=3;
    if(a==23)
    index=4;
    if(a==42)
    index=5;
    if(index!=0){
      if(hash[index-1]>hash[index])
      hash[index]++;
    }
  }

  for(auto x:hash)
  val = min(val,x);
  cout<<n-val*6;
 	return 0;
 }
