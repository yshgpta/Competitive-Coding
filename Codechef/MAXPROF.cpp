//ysh_gpta
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
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
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<endl; cout<<endl; }
int main(){
   FastIO
   ll t;
   cin>>t;
   while(t--){
       ll n,W,x,y;
       cin>>n>>W>>x>>y;
       ll mxn=max(x,y);
       ll mnn=min(x,y);
       ll dp[n+1][W+1];
       vi nt(n),wt(n);
       for(int i=0;i<n;i++)
       cin>>wt[i];
       for(int j=0;j<n;j++)
       cin>>nt[j];
       for(int i=0;i<=n;i++){
           for(int j=0;j<=W;j++){
               if(i==0 || j==0)
               dp[i][j]=0;
               else if(j<wt[i-1])
               dp[i][j] = dp[i-1][j];
               else
               dp[i][j] = max(dp[i-1][j],nt[i-1]+dp[i-1][j-wt[i-1]]);
           }
       }


        int res = dp[n][W];
        ll w = W;     
        vi ans;
        for (int i=n; i > 0 && res > 0; i--) {  
            if (res == dp[i - 1][w])  
                continue;         
            else { 
                ans.pb(nt[i-1]);
                res = res - nt[i - 1]; 
                w = w - wt[i - 1]; 
            } 
        } 

        ll cnt =0;
        sort(ans.begin(),ans.end(),greater<ll>());
        
        // for(int i=0;i<n;i++)
        if(ans.size()>=2)
        cnt+=ans[0]*(mxn-1) + ans[1]*(mnn-1);
        else
        cnt+=ans[0]*(mxn-1);
        cout<<dp[n][W]+cnt<<endl;
    }
   return 0;
}