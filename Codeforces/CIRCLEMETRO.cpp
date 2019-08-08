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
 	int n,a,x,b,y;
  cin>>n>>a>>x>>b>>y;
  int posx=--a,posy=--b;
  int flag;
  x--;
  y--;
  for(int i=1;;i++){
    if(posx==posy){
      flag=1;
      break;
    }
    if(x==posx || y==posy){
      flag=0;
      break;
    }
    posx = (posx+1)%n;
    if(posy==0)
    posy=n-1;
    else
    posy--;
  }
  if(flag==1)
  cout<<"YES";
  else
  cout<<"NO";
 	return 0;
 }
