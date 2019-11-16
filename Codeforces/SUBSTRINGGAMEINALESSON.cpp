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
int main(){
   FastIO
   string str;
   cin>>str;
   char max=str[0];
   char min=str[0];
   cout<<"Mike"<<endl;
   for(int i=1;i<str.length();i++){
       bool flag=0;
       if(str[i]>min){
           flag = 1;
       }
       if(str[i]<=min)
       min=str[i];
    	if(flag)
        cout<<"Ann"<<endl;
    	else 
        cout<<"Mike"<<endl;
   }
   return 0;
}