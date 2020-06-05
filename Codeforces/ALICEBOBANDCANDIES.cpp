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
        vi v(n+1);
        vi sum(n+1,0);
        repf(i,1,n+1){
            cin>>v[i];;
            sum[i] = sum[i-1]+v[i];
        }
        if(n==1){
            cout<<1<<" "<<sum[n]<<" "<<0<<endl;
            continue;
        }
        ll a=v[1];
        ll b;
        ll count=1;
        ll ai=1;
        ll bi=n;
        while(sum[n]-sum[bi]<=a && bi>ai){
            bi--;
        }
        b = sum[n]-sum[bi];
        // cout<<a<<" "<<b<<endl;
        // cout<<ai<<" "<<bi<<endl;
        bi++;
        if(bi>ai){
            
            count++;
            while(ai<bi){
                ll j=ai+1;
                if(j>=bi)
                break;
                a = sum[j]-sum[ai];
                // cout<<"a"<<a;
                while(sum[j]-sum[ai]<=b && j<bi){

                    j++;
                }
                if(j<bi){
                    a = sum[j]-sum[ai];
                    ai=j;
                    // cout<<"a"<<a<<endl;
                    // cout<<"ai"<<ai<<endl;;
                    count++;
                    // cout<<count<<endl;
                }
                else{
                    a = sum[j-1]-sum[ai];
                    ai=j-1;
                    // cout<<"a"<<a<<endl;
                    // cout<<"ai"<<ai<<endl;
                    count++;
                    // cout<<count<<endl;
                    break;
                }
                j=bi-1;
                if(j<=ai)
                break;
                b = sum[bi-1]-sum[j];
                // cout<<"b"<<b<<endl;
                while(sum[bi-1]-sum[j]<=a && j>ai){
                    
                    j--;
                }
                if(j>ai){
                    b = sum[bi-1]-sum[j];
                    bi = j;
                    bi++;
                    // cout<<"b"<<b<<endl;
                    // cout<<"bi"<<bi<<endl;
                    // cout<<"Hell";
                    count++;
                    // cout<<count<<endl;
                }else{
                    b = sum[bi-1]-sum[j];
                    bi=j+1;
                    // cout<<"b"<<b<<endl;
                    // cout<<"bi"<<bi<<endl;
                    count++;
                    // cout<<count<<endl;
                    break;
                } 
            }
        }
        // cout<<ai<<" "<<bi<<endl;
        cout<<count<<" "<<sum[ai]-sum[0]<<" "<<sum[n]-sum[ai]<<endl;
        
        

    }
    return 0;
}