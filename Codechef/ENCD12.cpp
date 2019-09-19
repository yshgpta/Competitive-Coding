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
   while(true){
       cin>>str;
       if(str=="0")
       break;
       int i=0;
       int j=str.length()-1;
       int c=0;
       while(i<=j){
           if(str[i]==str[j]){
               i++;
               j--;
           }else{
               int k = j-1;
               while(k>i && str[k]!=str[i])
               k--;
               if(k<=i){
                   c=-1;
                   break;
               }
               while(k<j){
                   c++;
                   swap(str[k],str[k+1]);
                   k++;
               }
           }
       }
       if(c==-1)
       cout<<"Impossible"<<endl;
       else
       cout<<c<<endl;
   }
   return 0;
}