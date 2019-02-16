#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    vector<int> a(26,0);
    vector<int>result;
    for(int i=0;i<str.length();i++)
    a[str[i]-'A']++;

    long sum=0;
    for(int i=0;i<26;i++)
    sum+=a[i];

    sort(a.begin(),a.end(),greater<int>());
    long n = str.length();
    for(int i=1;i<=26;i++){
      long res =0;
      if(n%i==0){
        long occur=n/i;
        long sum1 =0;
        for(int j=0;j<i && j<26;j++){
          sum1 += a[j];
          if(a[j]>occur)
          res += a[j]-occur;
        }
        res += sum - sum1;
        result.push_back(res);
      }
    }
    sort(result.begin(),result.end());
    cout<<result[0]<<endl;
  }
  return 0;
}
