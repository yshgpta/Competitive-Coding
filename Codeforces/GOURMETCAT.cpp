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

bool isZero(ll a){
  if(a==0)
  return true;
  return false;
}

 ll singleWeek(ll a,ll b,ll c){
   int arr[]={1,2,3,1,3,2,1};
   ll maxcount=-1;
   for(int i=0;i<7;i++){
     int flag=0;
     ll count=0;
     ll a_temp = a;
     ll b_temp = b;
     ll c_temp = c;
     for(int j=i;j<7;j++){
       if(flag==1)
       break;
       if(arr[j]==1){
        if(!isZero(a_temp)){
          a_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
       if(arr[j]==2){
        if(!isZero(b_temp)){
          b_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
       if(arr[j]==3){
        if(!isZero(c_temp)){
          c_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
     }
     for(int j=0;j<i;j++){
       if(flag==1)
       break;
       if(arr[j]==1){
        if(!isZero(a_temp)){
          a_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
       if(arr[j]==2){
        if(!isZero(b_temp)){
          b_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
       if(arr[j]==3){
        if(!isZero(c_temp)){
          c_temp--;
          count++;
        }else{
          flag=1;
          break;
        }
       }
     }
     if(count>maxcount)
     maxcount=count;
   }
   return maxcount;
 }

 int main(){
 	FastIO
 	double a,b,c;
  cin>>a>>b>>c;
  double min;
  int flag=0;
  if(b>c)
  min=c;
  else
  min=b;
  if(min*1.5>a){
    flag=1;
    min=a;
  }
  ll count;
  if(a<3 || b<2 || c<2){
    count = singleWeek(a,b,c);
  }else{
    if(flag==0){
      int rem = c/2;
      count = rem*7;
      c = c-rem*2;
      b = b-rem*2;
      a = a-rem*3;
    }else{
      int rem=a/3;
      count = rem*7;
      a = a-rem*3;
      b = b-rem*2;
      c = c-rem*2;
    }
    count+=singleWeek(a,b,c);
  }
  cout<<count;
 	return 0;
 }
