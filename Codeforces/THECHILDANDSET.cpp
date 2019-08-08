#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define vpi vector<pair<ll,ll> >
 #define pb push_back
 #define mp make_pair
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 ll countZeroVal(ll num){
   ll cnt=0;
   while(num%2==0){
     num = num>>1;
     cnt++;
   }
   return pow(2,cnt);
 }

 bool comp(pair<ll,ll> &a,pair<ll,ll> &b){
   return a.ff>b.ff;
 }

 int main(){
 	FastIO
 	ll sum,limit;
  cin>>sum>>limit;
  vpi v;
  for(int i=1;i<=limit;i++){
    v.pb(mp(countZeroVal(i),i));
  }
  vi res;
  sort(v.begin(),v.end(),comp);
  for(int i=0;i<v.size();i++){
    if(sum>=v[i].ff){
      sum -= v[i].ff;
      res.pb(v[i].ss);
    }
  }
  if(sum==0){
    cout<<res.size()<<endl;
    for(int j=0;j<res.size();j++)
    cout<<res[j]<<" ";
  }
  else
  cout<<"-1";
 	return 0;
 }
