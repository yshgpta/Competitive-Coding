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
 	ll n;
  cin>>n;
  ll a,b;
  int flag=0;
  for(int i=5;i<=sqrt(n);i++){
    if(n%i==0){
      if(i==n/i){
        a=b=i;
        flag=1;
        break;
      }
      else{
        if(n/i>=5){
          a=i;
          b=n/i;
          flag=1;
          break;
        }
      }
    }
  }
  if(flag==0)
  cout<<-1;
  else{
    char arr[a][b];
    string vowel = "aeiou";
    string res;
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
        arr[i][j] = vowel[(i+j)%5];
        res = res+ arr[i][j];
      }
    }
    cout<<res;
  }
 	return 0;
 }
