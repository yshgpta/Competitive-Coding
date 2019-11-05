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

ll findval(vi v,ll diff,ll a_diff){
    ll r;
    for(int i=1;i<v.size();i++){
        if(diff==v[i]-v[i-1]){
            r =  v[i-1]+diff/2;
            if((r-v[i-1]) == a_diff)
            return  r;
            break;
        }
    }
    return INT_MIN;
}


int main(){
   FastIO
   ll n;
   cin>>n;
   vi v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   sort(v.begin(),v.end());
   set<ll> st;
   if(n==1){
       cout<<-1;
       return 0;
   }else if(n==2){
       if((v[0]%2==0 && v[1]%2==0) || (v[0]%2==1 && v[1]%2==1)){
           ll diff = v[1]-v[0];
           st.insert(v[0]-diff);
           st.insert(v[0]+diff/2);
           st.insert(v[1]+diff);
           cout<<st.size()<<endl;
            for(auto  it = st.begin();it!=st.end();it++)
            cout<<*it<<" ";
            return 0;
       }
   }

   map<ll,ll> mp;
   for(int i=1;i<n;i++){
       mp[v[i]-v[i-1]]++;
   }
   if(mp.size()==1){
       ll diff = v[1]-v[0];
       st.insert(v[0]-diff);
       st.insert(v[n-1]+diff);
   }else if(mp.size()==2){
       auto it1 = mp.begin();
       auto it2 = mp.begin();
       it2++;
       if(it1->ff==0 || it2->ff==0 || (it1->ss > 1 && it2->ss > 1)){
           cout<<0;
           return 0;
       }
       
       if(it1->ss == it2->ss){
           ll val;
           if(it1->ff > it2->ff)
            val = findval(v,it1->ff,it2->ff);
            else
            val = findval(v,it2->ff,it1->ff);
            if(val!=INT_MIN)
            st.insert(val);
            else{
                cout<<0;
                return 0;
            }
       }else{
           ll val;
           if(it1->ss > it2->ss)
           val = findval(v,it2->ff,it1->ff);
           else
           val = findval(v,it1->ff,it2->ff);
           if(val!=INT_MIN)
           st.insert(val);
           else{
               cout<<0;
               return 0;
           }
       }
   }else{
       cout<<0;
       return 0;
   }
   cout<<st.size()<<endl;
   for(auto  it = st.begin();it!=st.end();it++)
   cout<<*it<<" ";
   return 0;
}