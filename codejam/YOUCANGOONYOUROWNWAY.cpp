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
  for(int i=1;i<=t;i++){
    ll n;
    cin>>n;
    string str;
    cin>>str;
    for(int j=0;j<=str.size();j++){
      if(str[j]=='E')
      str[j]='S';
      else
      str[j]='E';
    }
    cout<<"Case #"<<i<<": "<<str<<endl;
  }
 	return 0;
 }
