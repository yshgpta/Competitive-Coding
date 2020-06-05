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


int main(){
    FastIO
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vi v(n);
        vi d(n);
        repf(i,0,n){
            cin>>v[i];
            d[v[i]]++;
        }
        if(*max_element(d.begin(),d.end())>2){
            cout<<0<<endl;
            continue;
        }
        set<ll> st1,st2;
        ll i=0;
        ll flag=0;
        ll idx1=-1;
        vpii res;
        for(i=0;i<n;i++){
            if(flag==0){
                if(st1.find(v[i])==st1.end()){
                    st1.insert(v[i]);
                }else{
                    flag=1;
                    idx1 = i;
                    idx1--;
                }
            }
            if(flag==1){
                if(st2.find(v[i])==st2.end()){
                    st2.insert(v[i]);
                }else{
                    break;
                }
            }
        }
        auto it1 = max_element(st1.begin(),st1.end());
        auto it2 = max_element(st2.begin(),st2.end());
        if(st1.size()==*it1 && st2.size()==*it2 && st1.size()+st2.size()==n){
            res.pb(mkp(st1.size(),st2.size()));
        }
        st1.clear();
        st2.clear();
        flag=0;
        ll idx2=-1;
        for(i=n-1;i>=0;i--){
            if(flag==0){
                if(st1.find(v[i])==st1.end()){
                    st1.insert(v[i]);
                }else{
                    flag=1;
                    idx2=i;
                }
            }
            if(flag==1){
                if(st2.find(v[i])==st2.end()){
                    st2.insert(v[i]);
                }else{
                    break;
                }
            }
        }
        it1 = max_element(st1.begin(),st1.end());
        it2 = max_element(st2.begin(),st2.end());;
        if(idx1!=idx2 && st1.size()==*it1 && st2.size()==*it2 && st1.size()+st2.size()==n){
            res.pb(mkp(st2.size(),st1.size()));
        }
        cout<<res.size()<<endl;
        if(res.size()){
            repf(j,0,res.size())
            cout<<res[j].ff<<" "<<res[j].ss<<endl;
        }
    }
    return 0;
}