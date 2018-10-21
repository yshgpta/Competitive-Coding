#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int total_sum=0;
    map<string,int> mm;
    string str;
    for(int i=0;i<n;i++){
      cin>>str;
      int sum = 2;
      if(mm.find(str)!=mm.end())
      total_sum += mm[str]/2;
      else{
      int left;
      if(str[0]=='d' || str[0]=='f')
      left=1;
      else
      left=0;
      for(int j=1;j<str.size();j++){
        if(left){
          if(str[j]=='d' || str[j]=='f')
          sum += 4;
          else{
            sum+=2;
            left=0;
          }
        }else{
          if(str[j]=='j' || str[j]=='k')
          sum += 4;
          else{
            sum += 2;
            left = 1;
          }
        }
      }
      mm[str]=sum;
      total_sum += sum;
      }
    }
    cout<<total_sum<<endl;
  }
  return 0;
}
