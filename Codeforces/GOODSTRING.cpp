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
  string str;
  cin>>str;
  string res;
  for(int i=0;i<n;i++){
    if(res.length()%2==0 || res.back()!=str[i])
    res.push_back(str[i]);
  }
  if(res.length()%2==1)
  res.pop_back();
  cout<<n-res.length()<<endl;
  cout<<res;
 	return 0;
 }
