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

ll seg_tree[300000];

void constructTree(vi &v,ll low,ll high,ll pos,bool flag){
    if(low==high){
        seg_tree[pos] = v[low];
        return;
    }
    ll mid = (low+high)/2;
    constructTree(v,low,mid,2*pos+1,!flag);
    constructTree(v,mid+1,high,2*pos+2,!flag);
    if(flag)
    seg_tree[pos] = seg_tree[2*pos+1] ^ seg_tree[2*pos+2];
    else
    seg_tree[pos] = seg_tree[2*pos+1] | seg_tree[2*pos+2];
}

void updateTree(ll low,ll high,ll val,ll index,ll pos,bool flag){
    if(index<low || index>high)
    return;
    if(low==high){
        seg_tree[pos]=val;
        return;
    }
    if(low != high){
        ll mid = (low+high)/2;
        updateTree(low,mid,val,index,2*pos+1,!flag);
        updateTree(mid+1,high,val,index,2*pos+2,!flag);
    }
    if(flag)
    seg_tree[pos] = seg_tree[2*pos+1] ^ seg_tree[2*pos+2];
    else
    seg_tree[pos] = seg_tree[2*pos+1] | seg_tree[2*pos+2];
}

int main(){
   FastIO
   ll n,m;
   cin>>n>>m;
   vi v(pow(2,n));
   for(int i=0;i<pow(2,n);i++)
   cin>>v[i];
   constructTree(v,0,v.size()-1,0,n%2==0);
//    for(int i=0;i<pow(2,n+1);i++)
//    cout<<seg_tree[i]<<" ";
   while(m--){
       ll index,val;
       cin>>index>>val;
       index--;
       v[index] = val;
       updateTree(0,v.size()-1,val,index,0,n%2==0);
        // for(int i=0;i<pow(2,n+1);i++)
        // cout<<seg_tree[i]<<" ";
        cout<<seg_tree[0]<<endl;
   }
   return 0;
}