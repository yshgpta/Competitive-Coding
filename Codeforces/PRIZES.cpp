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
int main(){
   FastIO
   ll n;
   cin>>n;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   vi arr(5);
   for(int i=0;i<5;i++)
   cin>>arr[i];
   ll excess=0;
   vi brr(5,0);
   for(int i=0;i<n;i++){
       ll val = v[i];
       ll total = val+excess;
       ll index = lower_bound(arr.begin(),arr.end(),total)-arr.begin();
       if(arr[index]!=total)
       index--;
    //    cout<<index<<endl;
       excess = total%arr[index];
       brr[index]+=total/arr[index];
       while(excess>=arr[0]){
           index = lower_bound(arr.begin(),arr.end(),excess)-arr.begin();
           if(arr[index]!=excess)
           index--;
        //    cout<<index<<endl;
           brr[index] += excess/arr[index];
           excess = excess%arr[index];
       }
   }
   for(int i=0;i<5;i++)
   cout<<brr[i]<<" ";
   cout<<endl;
   cout<<excess;
   return 0;
}