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
 	ll q;
  cin>>q;
  for(int i=0;i<q;i++){
    ll n;
    cin>>n;
    ll count=0;
    if(n==1){
      cout<<0<<endl;
      continue;      
    }
    while(n!=1){
      if(n%2==0)
      n=n/2;
      else if(n%3==0)
      n=(n/3)*2;
      else if(n%5==0)
      n=(n/5)*4;
      else{
        cout<<-1<<endl;
        break;
      }
      count++;
      if(n==1){
        cout<<count<<endl;
        break;
      }
    }
  }
 	return 0;
 }
