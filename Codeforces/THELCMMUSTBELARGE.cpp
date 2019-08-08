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
 	ll m,n;
  cin>>m>>n;
  vector<bitset<10000>> v(m);
  for(int i=0;i<m;i++){
    int s;
    cin>>s;
    for(int j=0;j<s;j++){
      int b;
      cin>>b;
      v[i][b]=1;
    }
  }
  int flag=0;
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      if((v[i] & v[j])==0){
        flag=1;
        break;
      }
    }
  }
  if(flag==0)
  cout<<"possible";
  else
  cout<<"impossible";
 	return 0;
 }
