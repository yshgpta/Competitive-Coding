#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
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
  for(int c=1;c<=t;c++){
    ll n;
    cin>>n;
    vi v;
    ll np=n;
    while(np!=0){
      int d = np%10;
      v.pb(d);
      np/=10;
    }
    reverse(v.begin(),v.end());
    // for(int i=0;i<v.size();i++)
    // cout<<v[i]<<" ";
    int odd = -1;
    for(int i=0;i<v.size();i++){
      if(v[i]%2!=0){
        odd=i;
        break;
      }
    }
    cout<<"Case #"<<c<<": ";
    if(odd==-1){
      cout<<0<<endl;
      continue;
    }
    ll m=0;
    for(int i=odd;i<v.size();i++)
    m = m*10+v[i];

    ll lowlimit = v[odd]-1;
    for(int i=odd+1;i<v.size();i++)
    lowlimit = lowlimit*10+8;

    if(v[odd]==9)
    cout<<m-lowlimit<<endl;
    else{
      ll upperlimit = v[odd]+1;
      for(int i=odd+1;i<v.size();i++)
      upperlimit*=10;
      cout<<min(m-lowlimit,upperlimit-m)<<endl;
    }
  }
 	return 0;
 }
