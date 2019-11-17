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

bool isValid(ll n,ll m,ll i,ll j){
    if(i>=0 && i<n && j>=0 && j<m)
    return true;
    return false;
}

int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n,m;
       cin>>n>>m;
       vvi a(n,vi(m));
       vvi b(n,vi(m));
       string str;
       for(int i=0;i<n;i++){
           cin>>str;
           for(int j=0;j<str.length();j++)
           a[i][j] = str[j]-'0';
       }
       for(int i=0;i<n;i++){
           cin>>str;
           for(int j=0;j<str.length();j++)
           b[i][j] = str[j]-'0';
       }
       ll count=INT_MAX;
       for(int dr=-n+1;dr<n;dr++){
           for(int dc=-m+1;dc<m;dc++){
               ll cnt=0;
               ll flag=0;
               for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(isValid(n,m,i+dr,j+dc)){
                            if(b[i+dr][j+dc]!=a[i][j])
                            cnt++;
                        }else{
                            if(a[i][j]==1)
                            cnt++;
                        }
                        // if(dr==-1 && dc==-1)
                        // cout<<cnt<<endl;
                    }
                }
                count = min(count,cnt);
           }
       }
       
       cout<<count<<endl;
       
   }
   
   return 0;
}