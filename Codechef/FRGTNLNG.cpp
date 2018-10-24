#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    map<string,int> mm;
    string str;
    for(int i=0;i<n;i++){
      cin>>str;
      mm[str]=i;
    }
    int arr[n]={0};
    for(int i=0;i<k;i++){
      int a;
      cin>>a;
      string s;
      while(a--){
        cin>>s;
        if(mm.find(s)!=mm.end()){
          arr[mm[s]]++;
        }
      }
    }
    for(int i=0;i<n;i++){
      if(arr[i])
      cout<<"YES"<<" ";
      else
      cout<<"NO"<<" ";
    }
    cout<<endl;
  }
  return 0;
}
