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

 bool haveNine(ll n){
   int flag=0;
   while(n!=0){
     int rem = n%10;
     n/=10;
     if(rem==9){
       flag=1;
       break;
     }
   }
   if(flag==1)
   return true;
   else
   return false;
 }

 bool isDivisible(ll n){
   ll sum=0;
   while(n!=0){
     int rem = n%10;
     sum+=rem;
     n/=10;
   }
   if(sum%9==0)
   return true;
   else
   return false;
 }

 int main(){
 	FastIO
 	int t;
  cin>>t;
  for(int j=1;j<=t;j++){
    ll f,l;
    cin>>f>>l;
    ll count=0;
    for(ll i=f;i<=l;i++){
      if(i>0){
        if(!isDivisible(i) && !haveNine(i))
        count++;
      }
    }
    cout<<"Case #"<<j<<": "<<count<<endl;
  }
 	return 0;
 }
