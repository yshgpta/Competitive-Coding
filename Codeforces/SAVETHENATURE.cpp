//ysh_gpta
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
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
        ll n;
        cin>>n;
        list<ll> p(n);
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            p.push_back(a/100);
        }
        double x,y,a,b;
        cin>>x>>a;
        cin>>y>>b;
        double k;
        cin>>k;
        p.sort();
        p.reverse();
        if(min(a,b)>n){
            cout<<"-1"<<endl;
            continue;
        }
        list<ll> va,vb,vab;
        for(int i=1;i<=n;i++){
            if(i%((ll)(a*b))==0)
            vab.pb(i);
            else{
                if(i%((ll)a)==0)
                va.pb(i);
                if(i%((ll)b)==0)
                vb.pb(i);
            } 
        }
        // ll num=va.size();
        // for(int i=0;i<num;i++){
        //             cout<<va.front()<<" ";
        //             va.pop_front();
        // }
        // cout<<endl;

        ll sum=0;
        ll count=0;
        ll flag=1;
        while(sum<k){
            if(va.size()==0 && vb.size()==0 && vab.size()==0){
                flag=0;
                break;
            }
            if((va.size()!=0) && (vb.size()==0 || va.front()<vb.front()) && (vab.size()==0 || va.front()<vab.front())){
                sum+=x*p.front();
                cout<<x*p.front()<<"va"<<endl;
                count=va.front();
                va.pop_front();
                p.pop_front();
            }else if((vb.size()!=0) && (va.size()==0||vb.front()<va.front()) && (vab.size()==0 || vb.front()<vab.front())){
                sum+=y*p.front();
                cout<<y*p.front()<<"vb"<<endl;
                count=vb.front();
                vb.pop_front();
                p.pop_front();
            }else if((vab.size()!=0) && (va.size()==0 || vab.front()<va.front()) && (vb.size()==0 || vab.front()<vb.front())){
                sum+=(x+y)*p.front();
                cout<<(x+y)*p.front()<<"vab"<<endl;
                count=vab.front();
                vab.pop_front();
                p.pop_front();
            }
        }
        if(flag==0)
        cout<<"-1"<<endl;
        else
        cout<<count<<endl;
   }
   return 0;
}