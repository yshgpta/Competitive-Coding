//ysh_gpta
#include<bits/stdc++.h>
#include<algorithm>
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;


#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define IN(i,l,r) (l<i&&i<r)   //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)


#define repf(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define repfe(i,L,R) for (int i = L; i <= R; i++)
#define repb(i,L,R) for (int i = L; i > R; i--)
#define repbe(i,L,R) for (int i = L; i >= R; i--)


typedef long long ll;
#define cerr if(false)cerr
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


#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}


vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

bool cmp(pii &a,pii &b){
    return a.ff>b.ff;
}

int main(){
    FastIO
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vi v(n+1);
        repf(i,1,n+1) cin>>v[i];
        vi st(n+1,0);
        repf(i,2,n){
            if(v[i]>v[i-1] && v[i]>v[i+1])
            st[i]=1;
        }
        vi pre(n+1,0);
        repf(i,2,n){
            pre[i] = pre[i-1]+st[i];
        }
        ll mx=-10000;
        ll idx;
        repfe(i,1,n-k+1){
            ll j=i+k-1;
            ll c=pre[j-1]-pre[i];
            if(c>mx){
                mx=c;
                idx=i;
            }
        }
        cout<<mx+1<<" "<<idx<<endl;
    }
    return 0;
}