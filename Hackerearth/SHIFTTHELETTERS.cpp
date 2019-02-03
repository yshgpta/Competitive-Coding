#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  cin>>str;
  int k;
  cin>>k;
  sort(str.begin(),str.end());
  int slen = str.length();
  int min_count = INT_MAX;
  for(int i=0;i<slen;i++){
    char s = str[i];
    int count = 0;
    int index = i+k+1;
    for(int j=0;j<slen-k-1;j++){
      if(index>=slen)
      index = index - slen;
      count += abs(s-str[index]);
      index++;
    }
    if(count<min_count)
    min_count = count;
  }
  cout<<min_count;
  return 0;
}
