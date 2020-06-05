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

ll nh,sh,et,wt;
ll md = 1e9;

ll solve(int t){
    string str;
    cin>>str;
    vi v(4,0);
    map<char,ll> mp;
    mp['N']=0;
    mp['S']=1;
    mp['E']=2;
    mp['W']=3;
    ll mx=1;
    stack<ll> st;
    repf(i,0,str.length()){
        if(str[i]>='E' && str[i]<='W'){
            v[mp[str[i]]] += mx;
        }else if(str[i]>='2' && str[i]<='9'){
            mx *= str[i]-'0';
            st.push(str[i]-'0');
        }else if(str[i]==')'){
            mx /= st.top();
            st.pop();
        }
    }
    ll x=1,y=1;
    y += v[1]-v[0];
    x += v[2]-v[3];
    if(x<=0){
        x = md - abs(x)%md;
        if(x==0) x=md;
    }else if(x>md){
        x = x%md;
        if(x==0) x=md;
    }
    if(y<=0){
        y = md - abs(y)%md;
        if(y==0) y=md;
    }else if(y>md){
        y = y%md;
        if(y==0) y=md;
    }
    // repf(i,0,4)
    // cout<<v[i]<<endl;
    cout<<"Case #"<<t<<": "<<x<<" "<<y<<endl;
}
int main(){
    FastIO
    ll t;
    cin>>t;
    repfe(i,1,t)
    solve(i);
    return 0;
}