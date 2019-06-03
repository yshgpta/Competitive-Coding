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
    ll n,ma,k;
    cin>>n>>ma>>k;
    map<string,int> m;
    ll a,b;
    vpii v;
    for(int i=0;i<k;i++){
      cin>>a>>b;
      v.pb(mp(a,b));
      m[to_string(a)+to_string(b)]=1;
    }
    ll sum=0;
    for(int i=0;i<v.size();i++){
      ll x = v[i].ff;
      ll y = v[i].ss;
      int count=0;
      if(x-1<=0)
      count++;
      else if(!(m.find(to_string(x-1)+to_string(y))!=m.end()))
      count++;
      if(x+1>n)
      count++;
      else if(!(m.find(to_string(x+1)+to_string(y))!=m.end()))
      count++;
      if(y-1<=0)
      count++;
      else if(!(m.find(to_string(x)+to_string(y-1))!=m.end()))
      count++;
      if(y+1>ma)
      count++;
      else if(!(m.find(to_string(x)+to_string(y+1))!=m.end()))
      count++;
      cout<<count<<" ";
      sum+=count;
    }
    cout<<sum<<endl;
  }
 	return 0;
 }
