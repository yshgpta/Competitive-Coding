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
// #define cerr if(false)cerr
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

ll dp[100005];
ll dph[100005];

int main(){
    FastIO
    ll n;
    cin>>n;
    vi h(n),v(n);
    repf(i,0,n){
        ll a;
        cin>>a;
        h[i] = --a;
    }
    repf(i,0,n)
    cin>>v[i];
    repf(i,0,n)
    dph[h[i]]=v[i];
    dp[0] = v[0];
    ll curr_h = h[0];
    ordered_set st;
    st.insert(h[0]);
    repf(i,1,n){
        if(curr_h<h[i]){
            dp[i] = dp[i-1]+v[i];
            curr_h=h[i];
            dph[h[i]] = dp[i];
            st.insert(h[i]);
        }else{
            auto ht = st.lower_bound(h[i]);
            // cout<<"ht"<<*ht<<endl;
            if(ht==st.begin()){
                if(dph[h[i]]>dp[i-1]){
                    dp[i] = dph[h[i]];
                    curr_h = h[i];
                }
                else
                {
                    dp[i] = dp[i-1];
                }
                
            }else{
                ht--;
                // cout<<"ht"<<*ht<<endl;
                ll val = *ht;
                if(dph[val]+v[i]>dp[i-1]){
                    dp[i] = dph[val] + v[i];
                    curr_h = h[i];
                    dph[h[i]] = dp[i];
                }
                else{
                    dp[i] = dp[i-1];
                    dph[h[i]] = dph[val] + v[i];
                }
            }
            st.insert(h[i]);
        }
                //     for(auto& it : st)
                // cout<<it<<" ";
                // cout<<endl;
    }
    // repf(i,0,n)
    // cout<<dp[i]<<" ";
    // cout<<endl;
    // repf(i,0,n)
    // cout<<dph[i]<<" ";
    cout<<dp[n-1];
    
    return 0;
}