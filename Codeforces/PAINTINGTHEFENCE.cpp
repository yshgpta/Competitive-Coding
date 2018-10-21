#include<bits/stdc++.h>
using namespace std;
int freq[30005]={0};
void paintFence(int *arr,int n,int key){
    int start = -1;
    for (int i=0; i<n; i++){
        if (arr[i] == key) {
            start = i;
            break;
        }
    }

    if (start == -1)
    return;
    int end = start;
    for (int i=n-1; i>=start; i--){
        if (arr[i] == key) {
            end = i;
            break;
        }
    }
    if (start == end)
    return;
    else{
      for(int i=start+1;i<end;i++){
        arr[i]=arr[start];
      }
    }
    return;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    freq[arr[i]]++;
  }
  int m;
  cin>>m;
  int order;
  for(int i=0;i<m;i++){
    cin>>order;
    if(freq[order]>=2)
    paintFence(arr,n,order);
  }
  for(int i=0;i<24;i++)
  cout<<freq[i]<<" ";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  return 0;
}
