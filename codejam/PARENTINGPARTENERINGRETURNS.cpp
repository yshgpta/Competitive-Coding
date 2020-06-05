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

bool isIntersect(pii &a,pii &b){
    return IN(b.ff,a.ff,a.ss) || IN(b.ss,a.ff,a.ss);
}

int main(){
    FastIO
    ll t;
    cin>>t;
    repfe(p,1,t){
        ll n;
        cin>>n;
        vpii v(n);
        repf(i,0,n)
        cin>>v[i].ff>>v[i].ss;
        vvi adj(n);
        repf(i,0,n){
            repf(j,i+1,n){
                // if(i==j)
                // continue;
                if(isIntersect(v[i],v[j])){
                    adj[i].pb(j);
                    // adj[j].pb(i);
                }
            }
        }
        // adj = {{1},{3,6},{5},{},{5,6},{},{}};
        vector<ll> ch(n,-1);
        ch[0]=1;
        ll flag=1;
        vi left;
        repf(i,0,n){
            ll u = ch[i];
            if(ch[i]==-1){
                left.pb(i);
                continue;
            }
            u = ch[i];
            repf(j,0,adj[i].size()){
                ll x=adj[i][j];
                if(ch[x]==-1)
                ch[x] = u^1;
                else if(ch[x]==(u^1))
                continue;
                else if(ch[x]!=(u^1)){
                    flag = 0;
                    break;
                }
            }
            // repf(k,0,n)
            // cout<<ch[k]<<" ";
            // cout<<endl;
            if(flag==0)
            break;
        }
        if(flag==1){
            repf(i,0,left.size()){
                ll z = left[i];

                
                if(ch[z]==-1){
                    if(adj[z].size()==0){
                        ch[z]=1;
                        // repf(k,0,n)
                        // cout<<ch[k]<<" ";
                        // cout<<endl;
                        continue;
                    }
                    vi option(3,0);
                    repf(j,0,adj[z].size()){
                    ll x = adj[z][j];
                    if(ch[x]==0)
                    option[0]=1;
                    else if(ch[x]==1)
                    option[1]=1;
                    else if(ch[x]==-1)
                    option[2]=1;
                    }
                    if(option[0] && option[1]){
                        flag=0;
                        break;
                    }else if(option[0]){
                        ch[z] = 1;
                    }else if(option[1]){
                        ch[z] = 0;
                    }else{
                        ch[z]=1;
                    }
                
                }
                ll u = ch[z];
                repf(j,0,adj[z].size()){
                ll x=adj[z][j];
                if(ch[x]==-1)
                ch[x] = u^1;
                else if(ch[x]==(u^1))
                continue;
                else if(ch[x]!=(u^1)){
                    flag = 0;
                    break;
                }
                }
                if(flag==0)
                break;
                // repf(k,0,n)
                // cout<<ch[k]<<" ";
                // cout<<endl;
            }
        }
        
        if(flag==0)
        cout<<"Case #"<<p<<": IMPOSSIBLE"<<endl;
        else{
            string res;
            repf(i,0,n){
                if(ch[i]==1)
                res+='J';
                else if(ch[i]==0)
                res+='C';
            }
            cout<<"Case #"<<p<<": "<<res<<endl;
        }
    }
    return 0;
}