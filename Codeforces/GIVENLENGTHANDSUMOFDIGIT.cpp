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
//ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

bool isPossible(ll m,ll s){
    return s>=0 && s<=9*m;
}

int main(){
   FastIO
   ll m,sum;
   cin>>m>>sum;
   if((sum==0 && m!=1) ||2 !isPossible(m,sum)){
       cout<<"-1 -1";
       return 0;
   }
   ll s =sum;
   string min,max;
   for(int i=0;i<m;i++){
       for(int d=0;d<10;d++){
           if((i>0||d>0||(m==1 && d==0)) && isPossible(m-i-1,s-d)){
               min += char('0'+d);
               s-=d;
               break;
           }
       }
   }
   s = sum;
   for(int i=0;i<m;i++){
       for(int d=9;d>=0;d--){
           if(isPossible(m-i-1,s-d)){
               max += char('0'+d);
               s-=d;
               break;
           }
       }
   }
   cout<<min<<" "<<max;
   return 0;
}