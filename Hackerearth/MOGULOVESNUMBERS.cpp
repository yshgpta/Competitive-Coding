#include<bits/stdc++.h>
using namespace std;
long arr[1000001]={0};
long val[1000001];
void initialize(){
  for(int i=2;i*i<=1000000;i++){
    if(arr[i]==0){
      for(int j=i*i;j<=1000000;j+=i){
        arr[j]=1;
      }
    }
  }
  for(int i=2;i<1000000;i++){
    if(arr[i]==0)
    val[i]=1;
    val[i] += val[i-1];
  }
}
int main(){
  initialize();
  int q;
  cin>>q;
  while(q--){
    int l,r;
    scanf("%d",&l);
    scanf("%d",&r);
    if(l>r)
    swap(l,r);
    printf("%d\n",val[r]-val[l-1]);
  }
}
