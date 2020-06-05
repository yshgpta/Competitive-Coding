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


ll bad;

void dfs(stack<ll>& st,ll node,vector<set<ll>>& adj,vi& vis,vi& recStack){
    vis[node] = 1;
    recStack[node] = 1;
    for(auto it : adj[node]){
        if(recStack[it])
        bad=1;
        else if(!vis[it])
        dfs(st,it,adj,vis,recStack);
    }
    recStack[node] = 0; 
    st.push(node);
}


int main(){
    FastIO
    ll t;
    cin>>t;
    repfe(p,1,t){
        ll n,m;
        cin>>n>>m;
        vector<vector<char> > v(n,vector<char>(m));
        vector<set<ll> > adj(26);
        set<ll> st;
        repf(i,0,n){
            string str;
            cin>>str;
            repf(j,0,m){
                v[i][j] = str[j];
                st.insert(str[j]);
            }
        }
        repf(i,0,n-1){
            repf(j,0,m){
                if(v[i][j]==v[i+1][j])
                continue;
                adj[v[i+1][j]-'A'].insert(v[i][j]-'A');
            }
        
        }
        vi vis(26,0);
        vi recStack(26,0);
        bad=0;
        stack<ll> stk;
        for(char ch : st){
            if(!vis[ch-'A'])
            dfs(stk,ch-'A',adj,vis,recStack);
        }
        if(bad==1){
            cout<<"Case #"<<p<<": "<<-1<<endl;
            continue;
        }
        string res;
        while(!stk.empty()){
            res+=char(stk.top()+'A');
            stk.pop();
        }
        cout<<"Case #"<<p<<": "<<res<<endl;
         
    }
    return 0;
}