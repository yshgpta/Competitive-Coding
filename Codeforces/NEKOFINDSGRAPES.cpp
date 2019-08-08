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
  ll odd_1=0,even_1=0;
  ll odd_2=0,even_2=0;
  ll a;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a%2==0)
    even_1++;
    else
    odd_1++;
  }
  for(int i=0;i<m;i++){
    cin>>a;
    if(a%2==0)
    even_2++;
    else
    odd_2++;
  }
  ll res = min(even_1,odd_2)+min(even_2,odd_1);
  cout<<res;
 	return 0;
 }
