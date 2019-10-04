//ysh_gpta
#include<bits/stdc++.h>
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

bool grid[310][310];
ll dp[310][310][310][2];
ll r,c,d;

ll solve(ll i,ll j,ll can,bool dn){
        if(i==r-1 && j==c-1)
        return 1;
        if(i>=r || i>=c || grid[i][j]==0)
        return 0;
        if(dp[i][j][can][dn]!=-1)
        return dp[i][j][can][dn];
        ll x=0;
        if(dn==1){
                if(can<d)
                x = (x + solve(i+1,j,can+1,1))%20011;
                x = (x + solve(i,j+1,1,0))%20011;
        }else{
                x = (x + solve(i+1,j,1,1))%20011;
                if(can<d)
                x = (x + solve(i,j+1,can+1,0))%20011; 
        }
        return dp[i][j][can][dn]=x;
}

int main(){
   FastIO
   cin>>r>>c>>d;
   for(int i=0;i<r;i++)
   for(int j=0;j<c;j++)
   cin>>grid[i][j];
   memset(dp,-1,sizeof(dp));
   cout<<solve(0,0,0,0);
   return 0;
}