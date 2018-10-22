#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int x,y,k,n;
    cin>>x>>y>>k>>n;
    int page,price,flag=0;
    for(int i=0;i<n;i++){
      cin>>page>>price;
      if(page>=x-y && price<=k){
        flag=1;
      }
    }
    if(flag==1)
    cout<<"LuckyChef"<<endl;
    else
    cout<<"UnluckyChef"<<endl;
  }
  return 0;
}
