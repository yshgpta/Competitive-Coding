//ysh_gpta
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
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
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<endl; cout<<endl; }
int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n;
       cin>>n;
       ll flag=0;
       ll sum=0;
       ll oddcnt=0;
       ll evencnt=0;
       for(int i=0;i<n;i++){
           ll a;
           cin>>a;
           sum+=a;
           if(a%2==1)
           oddcnt++;
           else
           evencnt++;
       }
       if(sum%2==1){
           cout<<"YES"<<endl;
       }else{
            if(n%2==0){
                if(oddcnt>0 && oddcnt!=n)
                cout<<"YES"<<endl;
                else
                cout<<"NO"<<endl;
            }else{
                if(oddcnt>0)
                cout<<"YES"<<endl;
                else
                cout<<"NO"<<endl;
            }
       }
   }
   return 0;
}