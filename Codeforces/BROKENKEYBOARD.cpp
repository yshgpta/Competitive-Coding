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
   ll q;
   cin>>q;
   while(q--){
       string str;
       cin>>str;
       vi v(26,0);
       vb visited(26,true);
       vi flag(26,0);
       for(int i=0;i<str.length();){
           char ch = str[i];
           ll count=0;
           while(ch == str[i]){
               count++;
               i++;
           }
        //    cout<<"count"<<count<<endl;
           if(flag[ch-'a']==0){
               if(count%2==0){
                //    cout<<"hello"<<endl;
               visited[ch-'a'] = false;
                }
                else{
                    visited[ch-'a']=true;
                    flag[ch-'a']=1;
                }
           }
       }
    //    for(int i=0;i<10;i++)
    //    cout<<flag[i]<<" ";
    //    cout<<endl;
    string res;
       for(int i=0;i<str.length();i++){
           if(visited[str[i]-'a']){
                res.pb(str[i]);
                visited[str[i]-'a']=false;
           }
       }
       sort(res.begin(),res.end());
       cout<<res<<endl;
   }
   return 0;
}