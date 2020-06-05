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

const int N = 1e6;
ll n;


struct node{
    ll a=0,b=0,c=0;
};

node sg_tree[2*N];

node combine(node l,node r){
    node v;
    ll t = min(l.a,r.b);
    v.a = l.a + r.a - t;
    v.b = l.b + r.b - t;
    v.c = l.c + r.c + 2*t;
    return v;
}

void build(){
    repb(i,n-1,0){
        sg_tree[i] = combine(sg_tree[i<<1],sg_tree[i<<1|1]);
    }
}


void p(node tree){
    cout<<tree.a<<" "<<tree.b<<" "<<tree.c<<endl;
}

node query(ll l,ll r){
    node resl,resr;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) resl = combine(resl,sg_tree[l++]);
        if(r&1) resr = combine(sg_tree[--r],resr);
        // cout<<"Left ";
        // cout<<l<<endl;
        // p(resl);
        // cout<<"Right ";
        // cout<<r<<endl;
        // p(resr);
    }
    return combine(resl,resr);
}


int main(){
    FastIO
    string str;
    cin>>str;
    n = str.length();
    repf(i,0,n){
        if(str[i]=='('){
            sg_tree[i+n].a = 1;
            sg_tree[i+n].b = 0;
            sg_tree[i+n].c = 0;
        }else{
            sg_tree[i+n].a = 0;
            sg_tree[i+n].b = 1;
            sg_tree[i+n].c = 0;
        }
    }
    build();
    // p(sg_tree[8]);
    // p(sg_tree[9]);
    // p(sg_tree[4]);
    // p(sg_tree[10]);
    // p(sg_tree[22]);
    // repf(i,0,2*n){
    //     cout<<sg_tree[i].ff<<" "<<sg_tree[i].ss<<endl;
    // }
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        cout<<query(l,r).c<<endl;
    }
    return 0;
}