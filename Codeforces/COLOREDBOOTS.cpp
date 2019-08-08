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
  string str1,str2;
  cin>>str1>>str2;
  vector<pair<char,ll> > v1, v2,cntsym1,cntsym2,cntleft1,cntleft2;
  vpii res;
  for(int i=1;i<=n;i++){
    v1.pb(mp(str1[i-1],i));
    v2.pb(mp(str2[i-1],i));
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  ll count=0;
  int i=0,j=0;
  while(i<n && j<n){
    if(v1[i].ff=='?' || v2[j].ff=='?'){
      if(v1[i].ff=='?'){
        cntsym1.pb(mp(v1[i].ff,v1[i].ss));
        i++;
      }
      if(v2[j].ff=='?'){
        cntsym2.pb(mp(v2[j].ff,v2[j].ss));
        j++;
      }
    }else if(v1[i].ff==v2[j].ff){
      count++;
      res.pb(mp(v1[i].ss,v2[j].ss));
      i++;
      j++;
    }else if(v1[i].ff>v2[j].ff){
      cntleft2.pb(mp(v2[j].ff,v2[j].ss));
      j++;
    }else if(v1[i].ff<v2[j].ff){
      cntleft1.pb(mp(v1[i].ff,v1[i].ss));
      i++;
    }
  }
  while(i<n){
    cntleft1.pb(mp(v1[i].ff,v1[i].ss));
    i++;
  }
  while(j<n){
    cntleft2.pb(mp(v2[j].ff,v2[j].ss));
    j++;
  }
  ll iter = min(cntleft1.size(),cntsym2.size());
  for(int i=0;i<iter;i++){
    pii left = cntleft1.back();
    cntleft1.pop_back();
    pii sym = cntsym2.back();
    cntsym2.pop_back();
    res.pb(mp(left.ss,sym.ss));
  }
  iter = min(cntleft2.size(),cntsym1.size());
  for(int i=0;i<iter;i++){
    pii left = cntleft2.back();
    cntleft2.pop_back();
    pii sym = cntsym1.back();
    cntsym1.pop_back();
    res.pb(mp(left.ss,sym.ss));
  }
  iter = min(cntsym1.size(),cntsym2.size());
  for(int i=0;i<iter;i++){
    pii sym1 = cntsym1.back();
    cntsym1.pop_back();
    pii sym2 = cntsym2.back();
    cntsym2.pop_back();
    res.pb(mp(sym1.ss,sym2.ss));
  }
  cout<<res.size()<<endl;
  if(res.size()>0){
    for(int i=0;i<res.size();i++){
      cout<<res[i].ff<<" "<<res[i].ss<<endl;
    }
  }
  // cout<<res.size()<<" "<<cntleft1.size()<<" "<<cntleft2.size()<<" "<<cntsym1.size()<<" "<<cntsym2.size();
 	return 0;
 }
