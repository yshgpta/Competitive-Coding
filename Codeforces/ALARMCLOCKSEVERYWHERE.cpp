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

 ll gcd( ll a, ll b ){
 	if(b==0){
 	     return a;
 	}
 	else{
 	     return gcd( b, a%b );
 	}
 }

 int main(){
 	FastIO
 	ll n,m;
  cin>>n>>m;
  vi arr(n);
  vi diff(n,0);
  cin>>arr[0];
  for(int i=1;i<n;i++) {
    cin>>arr[i];
    diff[i]=arr[i]-arr[i-1];
  }
  ll g=diff[1];
  for(int i=2;i<n;i++){
    g = gcd(g,diff[i]);
  }
  int flag=0;
  ll index=0;
  for(int i=0;i<m;i++){
    ll a;
    cin>>a;
    if(g%a==0){
      index=i+1;
      flag=1;
    }
  }
  if(flag==1){
    cout<<"YES"<<endl;
    cout<<arr[0]<<" "<<index;
  }else{
    cout<<"NO";
  }
 	return 0;
 }
