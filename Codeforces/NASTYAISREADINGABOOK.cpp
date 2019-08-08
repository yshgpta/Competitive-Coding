#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define pb push_back
 #define mp make_pair
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



 int main(){
 	FastIO
 	int n;
  cin>>n;
  vector<pii> v;
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    v.pb(mp(l,r));
  }
  int k;
  cin>>k;
  int i=0;
  while(k>v[i].ss){
    n--;
    i++;
  }
  cout<<n;
 	return 0;
 }
