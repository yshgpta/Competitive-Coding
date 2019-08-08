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

 findBit(ll x){
   int i=1;
   int index = 0;
   while(x){
     if(!(x&1))
     index = i;
     i++;
     x = x>>1;
   }
   return index;
 }

 int main(){
 	FastIO
 	ll x;
  cin>>x;
  vi v;
  int flag=0;
  if(x%2==0)
  flag=1;
  while(findBit(x)!=0){
    ll y=findBit(x);
    v.pb(y);
    ll num = pow(2,y)-1;
    x = x^num;
    if(findBit(x)!=0)
    x++;
  }
  if(v.size()==0)
  cout<<"0";
  else{
    if(flag==1)
    cout<<v.size()*2-1<<endl;
    else
    cout<<v.size()*2<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  }
 	return 0;
 }
