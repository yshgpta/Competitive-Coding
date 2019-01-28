#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  int left,right,top,down;
  int val,val1,val2,val3,val4;
  while(t--){
    int r,c,k;
    cin>>r>>c>>k;
    int val;
    left = abs(c-1);
    right = abs(8-c);
    top = abs(r-1);
    down = abs(8-r);
    if(top-k<0){
      val1 = top;
    }else{
      val1 = k;
    }
    if(right-k<0){
      val2 = right;
    }else{
      val2 = k;
    }
    if(down-k<0){
      val3 = down;
    }else{
      val3=k;
    }
    if(left-k<0){
      val4 = left;
    }else{
      val4 = k;
    }
    val = val1*val2 + val2*val3 + val3*val4 + val4*val1 + val1 + val2 + val3 + val4 + 1;
  cout<<val<<endl;
}
return 0;
}
