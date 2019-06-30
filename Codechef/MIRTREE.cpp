#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
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

cpp_int power(cpp_int a, cpp_int b)	//a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a)%MOD;
	cpp_int q = power(a,b/2);
	return (q*q)%MOD;
}

 int main(){
 	FastIO
 	cpp_int n,q;
  cin>>n>>q;
  cpp_int e = power(2,n+1)-2;
  cpp_int h = n+1;
  cpp_int l = power(2,n);
  cpp_int r=1;
  cpp_int a,x;
  cpp_int val;
  for(int i=0;i<q;i++){
    cin>>a;
    if(a==1){
      cin>>x;
      if(x==1 || x==2){
        val = ((e*2)%MOD + h)%MOD;
        r=r*2;
        e = val;
        l = l*2;
      }else if(x==4){
        h = h*2;
        val = ((e*2)%MOD + l)%MOD;
        e = val;
        l = r;
      }else{
        h=h*2;
        val = ((e*2)%MOD + r)%MOD;
        r = l;
        e = val;
      }
    }
    else{
      cout<<e<<endl;
    }
  }
 	return 0;
 }
