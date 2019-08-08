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
 	int n;
  cin>>n;
  set<ll> st;
  ll a;
  for(int i=0;i<n;i++){
    cin>>a;
    st.insert(a);
  }
  set<ll> :: iterator it;
  ll d;
  if(st.size()>3)
  d = -1;
  else if(st.size()==3){
    it = st.begin();
    ll d1 = abs(*it - *(++it));
    ll d2 = abs(*it - *(++it));
    if(d1==d2){
      d = d1;
    }else
    d=-1;
  }else if(st.size()==2){
    it = st.begin();
    d = abs(*it - *(++it));
    if(d%2==0)
    d=d/2;
  }else
  d = 0;
  cout<<d;
 	return 0;
 }
