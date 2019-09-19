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
   if(n%2==0){
       cout<<"NO";
       return 0;
   }
   vi arr(2*n+5);
   for(int i=1;i<=n;i++){
       arr[i] = 2*i-1;
   }
   for(int i=1;i<=n;i++){
       arr[i+n] = 2*i;
   }
   for(int i=2;i<=n;i+=2){
       swap(arr[i],arr[i+n]);
   }
   cout<<"YES"<<endl;
   for(int i=1;i<=2*n;i++)
   cout<<arr[i]<<" ";
   return 0;
}