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
ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
// vector<string> split(const string &s, char delim) 
// { 
//     vector<string> elems; 
//     stringstream ss(s); 
//     string item; 
//     while (getline(ss, item, delim)) 
//         elems.push_back(item); 
  
//     return elems; 
// } 
// vvi PowerSet(vi arr, int n) 
// { 
//     vector<string> list; 
//     for (int i = 0; i < (int) pow(2, n); i++) 
//     { 
//         string subset = ""; 
//         for (int j = 0; j < n; j++) 
//         { 
//             if ((i & (1 << j)) != 0) 
//                 subset += to_string(arr[j]) + "|"; 
//         } 
//         list.push_back(subset); 
//     } 
//     vvi v;
//     for (string subset : list) 
//     { 
//         vi a;
//         vector<string> arr = split(subset, '|'); 
//         for (string str: arr) 
//             a.pb(stoi(str));
//         v.pb(a); 
//     } 
//     return v;
// }
ll n;
vi arr(66);
vvi dp(66,vi(10005));
ll solve(int i,int curr_gcd){
    if(i==n){
        if(curr_gcd==1)
        return 1;
        else
        return 0;
    }
    if(dp[i][curr_gcd]!=-1)
    return dp[i][curr_gcd];
    else{
        dp[i][curr_gcd] = solve(i+1,curr_gcd) + solve(i+1,gcd(curr_gcd,arr[i]));
        return dp[i][curr_gcd];
    }
    
}

int main(){
   FastIO
   int t;
   cin>>t;
   while(t--){
       cin>>n;
       for(int i=0;i<n;i++)
       cin>>arr[i];
       for(int i=0;i<66;i++)
       for(int j=0;j<10005;j++)
       dp[i][j]=-1;
       ll ans = 0;
       for(int i=0;i<n;i++)
        ans += solve(i+1,arr[i]);
       cout<<ans<<endl;
   }
   return 0;
}