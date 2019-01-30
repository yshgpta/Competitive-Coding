#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,a,b;
    cin>>n>>a>>b;
    int mul = a*b;
    int a_size=0,b_size=0,c_size=0;
    long x;
    for(int i=0;i<n;i++){
      cin>>x;
      if(x%mul==0){
        c_size++;
      }
      else{
        if(x%b==0)
        a_size++;
        if(x%a==0)
        b_size++;
      }
    }

    if(!c_size){
      if(b_size>a_size)
      cout<<"BOB"<<endl;
      else
      cout<<"ALICE"<<endl;
    }else{
      if(b_size>=a_size)
      cout<<"BOB"<<endl;
      else
      cout<<"ALICE"<<endl;
    }
  }
  return 0;
}
