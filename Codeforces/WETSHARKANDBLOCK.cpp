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

ll n,b,k,x;
vi dp(101);
vi occr(10,0);

vvi matmul(vvi &a,vvi &b){
    ll n_row = a.size();
    ll n_col = b[0].size();
    ll x = a[0].size();
    vvi c(n_row,vi(n_col,0));
    repf(row,0,n_row){
        repf(col,0,n_col){
            repf(k,0,x){
                c[row][col] += (a[row][k] * b[k][col])%MOD;
            }
            c[row][col] %= MOD;
        }
    }
    return c;
}

vvi power(vvi m,ll e){
    if(e==1){
        return m;
    }
    vvi a = power(m,e/2);
    vvi ans = matmul(a,a);
    if(e%2==1)
    ans = matmul(ans,m);
    return ans;
}

int main(){
    FastIO
    cin>>n>>b>>k>>x;
    repf(i,0,n){
        ll a;
        cin>>a;
        occr[a]++;
    }
    vvi base(x);
    repf(i,0,x){
        if(i==0)
        base[i].pb(1);
        base[i].pb(0);
    }
    vvi t(x,vi(x,0));
    repf(j,0,x){
        repf(d,1,10){
            repf(a,0,x){
                if((a*10 + d)%x == j){
                    t[j][a] += occr[d];
                    // cout<<j<<" "<<a<<" "<<d<<" "<<t[j][a]<<endl;
                }
            }
        }
    }
    // repf(i,0,x){
    //     repf(j,0,x)
    //     cout<<t[i][j]<<" ";
    //     cout<<endl;
    // }
    vvi res = power(t,b);
    vvi ans = matmul(res,base);
    cout<<ans[k][0];
    return 0;
}