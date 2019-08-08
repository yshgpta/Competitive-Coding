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

 string findDiff(string str1, string str2)
{
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n2; i++)
    {
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

 int main(){
 	FastIO
 	int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    string str;
    cin>>str;
    string str1,str2;
    str1=str;
    for(int j=0;j<str1.size();j++){
      if((str1[j]-'0')==4)
      str1[j]='3';
    }
    str2 = findDiff(str,str1);
    cout<<"Case #"<<i<<": "<<str1<<" "<<str2<<endl;
  }
 	return 0;
 }
