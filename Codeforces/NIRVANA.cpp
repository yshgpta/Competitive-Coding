#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define vpii vector<pair<ll,ll> >
 #define mp make_pair
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 int product(int x)
 {
     int prod = 1;
     while (x) {
         prod *= (x % 10);
         x /= 10;
     }
     return prod;
 }

 int findNumber(int l, int r)
 {
     string a = to_string(l);
     string b = to_string(r);

     int ans = r;
     for (int i = 0; i < b.size(); i++) {
         if (b[i] == '0')
             continue;

         string curr = b;
         curr[i] = ((curr[i] - '0') - 1) + '0';

         for (int j = i + 1; j < curr.size(); j++)
             curr[j] = '9';

         int num = 0;
         for (auto c : curr)
             num = num * 10 + (c - '0');

         if (num >= l && product(ans) < product(num))
             ans = num;
     }

     return product(ans);
 }

 int main(){
 	FastIO
 	ll n;
  cin>>n;
  cout<<findNumber(0,n);
 	return 0;
 }
