//ysh_gpta
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vb vector<bool>
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define mkp make_pair
#define pb push_back
#define INF 1000000000000000
#define MOD 1000000007
#define ff first
#define ss second
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll gcd( ll a, ll b ){
   if(b==0){
        return a;
   }
   else{
        return gcd( b, a%b );
   }
}
int main(){
   FastIO
   int n;
   cin>>n;
   ll count=0;
   ll nnum=0;
   ll pnum=0;
   ll nzeros=0;
   for(int i=0;i<n;i++){
      int a;
      cin>>a;
      if(a<0){
          count+= abs(-1-a);
          nnum ++;
      }else if(a>0){
          count+=abs(a-1);
          pnum++;
      }else{
          nzeros++;
      }
   }
    if(nzeros>0){
        if(nnum%2==0)
        count+=nzeros;
        else{
            count++;
            count += nzeros-1;
        }
    }else{
        if(nnum%2!=0)
        count += 2;
    }
    cout<<count;
   return 0;
}