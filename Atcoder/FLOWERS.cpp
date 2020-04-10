//ysh_gpta
#include<bits/stdc++.h>
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

ll N = 2e5+5;
vi t(2*N,0);
ll n;

void modify(ll p,ll value){
    for(t[p+=n] = value; p>1 ; p>>=1) t[p>>1] = max(t[p],t[p^1]);
}

ll query(ll l,ll r){
    ll res = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) res = max(res,t[l++]);
        if(r&1) res = max(res,t[--r]);
    }
    return res;
}


int main(){
    FastIO
    cin>>n;
    vi h(n),a(n);
    repf(i,0,n)
    cin>>h[i];
    repf(i,0,n)
    cin>>a[i];
    vi dp(n,0);
    dp[0] = a[0];
    modify(h[0]-1,dp[0]);
    repf(i,1,n){
        dp[i] = query(0,h[i]) + a[i];
        modify(h[i]-1,dp[i]);
    }
    cout<<t[1];

    return 0;
}