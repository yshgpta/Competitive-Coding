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

vi ans(200050);

 int main(){
 	FastIO
 	ll n;
  cin>>n;
  vi v1,v2;
  ll w=0;
  for(int i=1;i<=n;i++){
    int a,b;
    cin>>a>>b;
    if(a==1)
    v1.pb(b);
    else
    v2.pb(b);
    w+=a;
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  vi one = v1;
  vi two = v2;
  ll cur=0;
  for(int i=2;i<=w;i+=2){
    ll cost1=0,cost2=0;
    if(two.size()>=1){
      cost2 = two[two.size()-1];
    }
    int flag=1;
    if(one.size()>=2){
      cost1 = one[one.size()-1]+one[one.size()-2];
    }else if(one.size()==1){
      cost1 = one[0];
      flag=0;
    }
    if(cost2>cost1){
      cur+=cost2;
      two.pop_back();
    }else{
      cur+=cost1;
      if(flag==1){
        one.pop_back();
        one.pop_back();
      }
      else
      one.pop_back();
    }
    ans[i]=cur;
  }
  one = v1;
  two = v2;
  cur=0;
  if(one.size()>=1){
    cur=one[one.size()-1];
    one.pop_back();
  }
  ans[1]=cur;
  for(int i=3;i<=w;i+=2){
    ll cost1=0,cost2=0;
    if(two.size()>=1){
      cost2 = two[two.size()-1];
    }
    int flag=1;
    if(one.size()>=2){
      cost1 = one[one.size()-1]+one[one.size()-2];
    }else if(one.size()==1){
      cost1 = one[0];
      flag=0;
    }
    if(cost2>cost1){
      cur+=cost2;
      two.pop_back();
    }else{
      cur+=cost1;
      if(flag==1){
        one.pop_back();
        one.pop_back();
      }
      else
      one.pop_back();
    }
    ans[i]=cur;
  }
  for(int i=1;i<=w;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
 	return 0;
 }
