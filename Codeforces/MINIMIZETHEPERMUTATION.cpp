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
vi find_min(ll start,vi &v,ll n){
    ll min=INT_MAX;
    vi res(2);
    for(int i=start;i<n;i++){
        if(min>v[i]){
            res[0]=v[i];
            res[1]=i;
        }
    }
    return res;
}
int main(){
   FastIO
   ll q;
   cin>>q;
   while(q--){
       ll n;
       cin>>n;
       vi v(n);
       for(int i=0;i<n;i++){
           cin>>v[i];
       }
       ll limit=0;
       ll i=0;
       ll left=n-1;
       while(i<n-1){
           ll arr = min_element(v.begin()+i,v.end())-v.begin();
        //    cout<<arr<<endl;
           if(arr>limit){
            //    cout<<"hello"<<endl;
               ll index = arr;
               while(left!=0 && index>limit && index>0){
               swap(v[index],v[index-1]);
               index--;
               left--;
            }
            limit=arr;
           }else if(limit==arr){
               limit++;
           }
           
           i++;
       }
       for(int i=0;i<n;i++)
       cout<<v[i]<<" ";
       cout<<endl;
   }
   return 0;
}