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

string openp(int a){
    string res;
    repf(i,0,a)
    res += '(';
    return res;
}

string closep(int a){
    string res;
    repf(i,0,a)
    res+=')';
    return res;
}

int main(){
    FastIO
    ll t;
    cin>>t;
    repfe(p,1,t){
        string str;
        cin>>str;
        ll n = str.length();
        string res;
        ll prev = str[0]-'0';
        ll curr = prev;
        res = openp(prev) + str[0];
        repf(i,1,n){
            curr = str[i]-'0';
            if(prev>curr)
            res = res + closep(prev-curr) + str[i];
            else
            res = res + openp(curr-prev) + str[i];
            prev = curr;
        }
        res = res + closep(curr);
        cout<<"Case #"<<p<<": "<<res<<endl;
    }
    return 0;
}