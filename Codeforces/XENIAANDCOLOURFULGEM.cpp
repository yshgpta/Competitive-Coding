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



ll cal(ll x, ll y, ll z) {
    return (ll)(x-y)*(x-y)+(ll)(y-z)*(y-z)+(ll)(z-x)*(z-x);
}
int main(){
    FastIO
    ll t;
    cin>>t;
    while(t--){
        vi cnt(3);
        cin>>cnt[0]>>cnt[1]>>cnt[2];
        vvi v(3);
        repf(i,0,cnt[0]){ ll a; cin>>a; v[0].pb(a);}
        repf(i,0,cnt[1]) { ll a; cin>>a; v[1].pb(a);}
        repf(i,0,cnt[2]) { ll a; cin>>a; v[2].pb(a);}
        repf(i,0,3) sort(all(v[i]));
        ll ans = LONG_LONG_MAX;
        repf(i,0,3){
            repf(j,0,3){
                if(i==j) continue;
                ll k = 3-i-j;
                // cout<<i<<" "<<j<<" "<<k<<endl;
                repf(p,0,cnt[i]){
                    ll val = v[i][p];
                    // cout<<val<<endl;
                    ll x = upper_bound(v[j].begin(),v[j].end(),val) - v[j].begin();
                    ll y = lower_bound(v[k].begin(),v[k].end(),val) - v[k].begin();
                    if(x==0 || y==cnt[k])
                    continue;
                    x--;
                    // cout<<p<<" "<<x<<" "<<y<<endl;
                    // cout<<val<<" "<<v[j][x]<<" "<<v[k][y]<<endl;
                    ans = min(ans,cal(val,v[j][x],v[k][y]));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}