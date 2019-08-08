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


ll strxor(string str,int x,int y){
  ll count=0;
  int i=str.length()-1,j=1;
  for(;j<=x;i--,j++){
    if(j==y+1){
      if((str[i]-'0')^1==1)
      count++;
    }else{
      int val =(str[i]-'0')^0;
      if(val==1)
      count++;
    }
  }
  return count;
}

 int main(){
 	FastIO
 	ll n,x,y;
  cin>>n>>x>>y;
  string str;
  cin>>str;
  ll res = strxor(str,x,y);
  cout<<res;
 	return 0;
 }
