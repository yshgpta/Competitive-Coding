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
       stack<char> st;
       stack<char> temp;
       for(int i=0;i<str.length();i++){
           if(st.empty())
           st.push(str[i]);
           else{
               char ch = st.top();
               int num = str[i]-'0';
               while(num<(ch-'0')){
                   if(num%2==0 && (ch-'0')%2==1){
                       temp.push(st.top());
                       st.pop();
                   }else if(num%2==1 && (ch-'0')%2==0){
                       temp.push(st.top());
                       st.pop();
                   }
                   ch = st.top();
               }
               st.push(str[i]);
               while(!temp.empty()){
                   st.push(temp.top());
                   temp.pop();
               }
           }
       }
       string res;
       while(!st.empty()){
           res = st.top()+res;
           st.pop();
       }
       cout<<res<<endl;
   }
   return 0;
}