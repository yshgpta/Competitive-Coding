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

ll n,k,p;

ll rec(ll st,ll taken,vvi &sum,vvi &dp){
    if(taken==p)
    return 0;
    if(st>n || taken>p)
    return -1e9;
    if(dp[st][taken]!=-1)
    return dp[st][taken];
    ll ans = -1e9;
    repfe(i,0,k){
        ans = max(ans,sum[st][i] + rec(st+1,taken+i,sum,dp));
    }
    return dp[st][taken] = ans;
}

ll solve(){
    cin>>n>>k>>p;
    vvi v(n+1,vi(k+1));
    vvi sum(n+1,vi(k+1,0));
    vvi dp(n+1,vi(p+1,-1));
    repf(i,1,n+1){
        repf(j,1,k+1){
            cin>>v[i][j];
            sum[i][j] = sum[i][j-1] + v[i][j];
        }
    }
    return rec(1,0,sum,dp);
}
int main(){
    FastIO
    ll t;
    cin>>t;
    repfe(i,1,t)
    cout<<"Case #"<<i<<": "<<solve()<<endl;
    return 0;
}