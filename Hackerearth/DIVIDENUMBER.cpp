#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n%2==0){
      vector <int> arr;
      for(int i=1;i<=n/2;i++){
        if(n%i==0)
        arr.push_back(i);
      }
      unsigned long long max=0,res;
      for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
          for(int k=0;k<arr.size();k++){
            if((2*arr[i]+arr[j]+arr[k])==n){
              res = arr[i]*arr[i];
              res = res*arr[j]*arr[k];
              if(res>max)
              max=res;
            }
          }
        }
      }
      if(max!=0)
      cout<<max<<endl;
      else
      cout<<"-1"<<endl;
    }
    else{
      cout<<"-1"<<endl;
    }
  }
  return 0;
}
