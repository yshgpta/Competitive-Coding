#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<long> arr;
    long a;
    int b=0;
    for(int i=0;i<n;i++){
      cin>>a;
      arr.push_back(a);
      if(i>=1)
      {
        if(arr[i]<arr[i-1])
          b++;
      }
    }
    if(b>=2)
      cout<<"NO"<<endl;
    else if(b==0)
      cout<<"YES"<<endl;
    else if(b==1)
    {
      if(arr[n-1]<=arr[0])
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
  }
  return 0;
}
