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
 #define NO_OF_CHARS 256
 bool canFormPalindrome(string str)
{
    int count[NO_OF_CHARS] = {0};
    for (int i = 0; str[i];  i++)
        count[str[i]]++;
    int odd = 0;
    for (int i = 0; i < NO_OF_CHARS; i++){
        if (count[i] & 1)
            odd++;

        if (odd > 1)
            return false;
    }
    return true;
}

 int main(){
 	FastIO
 	int t;
  cin>>t;
  for(int j=1;j<=t;j++){
    ll n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    ll count=0;
    for(int i=1;i<=q;i++){
      int l,r;
      cin>>l>>r;
      if(canFormPalindrome(str.substr(l-1,r-l+1))){
        count++;
      }
    }
    cout<<"Case #"<<j<<": "<<count<<endl;
  }
 	return 0;
 }
