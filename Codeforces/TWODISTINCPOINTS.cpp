#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    long l1,l2,r1,r2;
    cin>>l1>>r1>>l2>>r2;
    long mid1=(l1+r1)/2;
    long mid2=(l2+r2)/2;
    if(mid1!=mid2)
    cout<<mid1<<" "<<mid2<<endl;
    else
    cout<<mid1<<" "<<mid2+1<<endl;
  }
  return 0;
}
