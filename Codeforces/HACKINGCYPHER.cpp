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

int main(){
   FastIO
//    string str;
//    cin>>str;
//    ll a;
//    ll b;
//    cin>>a>>b;
//    string ans; 
// 	ll idx = 0;
//     ll rem1,rem2; 
// 	ll temp = str[idx] - '0';
// 	ll temp2;
// 	string s1,s2;
// 	while (temp < a) 
// 	temp = temp * 10 + (str[++idx] - '0');  
// 	while (str.size() > idx){ 
// 		ans += (temp / a) + '0'; 
//         rem1 = temp % a;
// 		temp = (temp % a) * 10 + str[++idx] - '0'; 
// 		temp2 = str[idx]-'0';
//         if(rem1==0){
// 			ll i =idx;
// 			s1 = str.substr(0,i);
// 			while (temp2 < b) 
// 			temp2 = temp2 * 10 + (str[++idx] - '0'); 
// 			while(str.size()>idx){
// 				rem2 = temp2 % b;
// 				temp2 = (temp2%b)*10 + str[++idx]-'0';
// 				if(rem2==0){
// 					s2 = str.substr(i,str.size()-i);
// 					ll j=0;
// 					if(s1[j]=='0'){
// 						while(s1[j]=='0'){
// 							j++;
// 						}
// 						s1 = s1.substr(j,s1.length()-j);
// 					}
// 					j=0;
// 					if(s2[j]=='0'){
// 						while(s2[j]=='0'){
// 							s1+='0';
// 							j++;
// 						}
// 						s2 = s2.substr(j,s2.length()-j);
// 					}
// 					cout<<"YES"<<endl;
// 					cout<<s1<<endl;
// 					cout<<s2;
// 					return 0;
// 				}
// 			}
// 		}
// 	}
// 	cout<<"NO";
	ll  c = 0, n = 0, p=1, i;
vector<ll> d(1<<21,0);
string m;
cin>>m;
n=m.length();
ll a,b;
cin>>a>>b;

  for (i=n-1; i>=0; i--) {
    d[i] = ((m[i] - '0') * p + d[i + 1]) % b;
    p = p * 10 % b;
  }
  for (i=1; i<n; i++) {
    c = (c * 10 + m[i - 1] - '0') % a;
    if (!c && !d[i] && m[i] != '0') {
      printf("YES\n");
      printf("%s\n%s\n", m.substr(0,i).c_str(), m.substr(i).c_str());
      return 0;
    }
  }
printf("NO\n");
return 0; 
   return 0;
}