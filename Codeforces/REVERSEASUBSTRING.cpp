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
  string str;
  cin>>str;
  int flag=0;
  ll index1=0,index2=0;
  for(int i=0;i<str.length()-1;i++){
    if(str[i]>str[i+1]){
      index1 = i+1;
      index2 = i+2;
      flag=1;
      break;
    }
  }
  if(flag==0)
  cout<<"NO";
  else{
    cout<<"YES"<<endl;
    cout<<index1<<" "<<index2;
  }
 	return 0;
 }
