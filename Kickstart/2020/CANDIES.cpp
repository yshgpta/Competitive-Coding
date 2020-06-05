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
const ll N =2*2*1e5+2;
vi t1(N);
vi tn1(N);
vi t2(N);
vi tn2(N);
ll n;

void build(vi &t) {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(vi &t,int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(vi &t,int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

ll solve(){
    ll q;
    cin>>n>>q;
    ll a;
    vi v(n);
    repf(i,0,n) cin>>v[i];
    repf(i,0,n){
        if(i%2==1){
            t1[n+i] = -v[i];
            tn1[n+i] = -(i+1)*v[i];
            t2[n+i] = v[i];
            tn2[n+i] = (i+1)*v[i];
        }else{
            t1[n+i] = v[i];
            tn1[n+i] = (i+1)*v[i];
            t2[n+i] = -v[i];
            tn2[n+i] = -(i+1)*v[i];
        }
    }
    repf(i,0,n) cout<<t1[n+i]<<" ";
    cout<<endl;
    repf(i,0,n) cout<<tn1[n+i]<<" ";
    cout<<endl;
    repf(i,0,n) cout<<t2[n+i]<<" ";
    cout<<endl;
    repf(i,0,n) cout<<tn2[n+i]<<" ";
    cout<<endl;

    build(t1); build(tn1); build(t2); build(tn2);
    char ch;
    ll sum=0;
    repf(i,0,q){
        cin>>ch;
        if(ch=='Q'){
            ll l,r;
            cin>>l>>r;
            if(l%2==0){
                sum+= query(tn2,l-1,r)-(l-1)*query(t2,l-1,r);
                cout<<query(tn2,l-1,r)-(l-1)*query(t2,l-1,r)<<endl;
            }else{
                sum += query(tn1,l-1,r)-(l-1)*query(t1,l-1,r);
                cout<<query(tn1,l-1,r)-(l-1)*query(t1,l-1,r)<<endl;
            }
        }else{
            ll p,val;
            cin>>p>>val;
            p--;
            if(p%2==1){
                modify(t1,p,-val);modify(tn1,p,-(p+1)*val);modify(t2,p,val);modify(tn2,p,(p+1)*val);
                repf(i,0,n) cout<<t1[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<tn1[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<t2[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<tn2[n+i]<<" ";
                cout<<endl;
            }else{
                modify(t2,p,-val);modify(tn2,p,-(p+1)*val);modify(t1,p,val);modify(tn1,p,(p+1)*val);
                repf(i,0,n) cout<<t1[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<tn1[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<t2[n+i]<<" ";
                cout<<endl;
                repf(i,0,n) cout<<tn2[n+i]<<" ";
                cout<<endl;
            }
        }
    }
    return sum;
}
int main(){
    FastIO
    ll test;
    cin>>test;
    repfe(i,1,test)
    cout<<"Case #"<<i<<": "<<solve()<<endl;
    return 0;
}