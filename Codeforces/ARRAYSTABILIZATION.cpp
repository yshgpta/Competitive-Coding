#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  vector<int> :: iterator it;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  sort(arr.begin(),arr.end());
  it = arr.begin();
  int first_element = *it;
  it++;
  int second_element = *it;
  it = arr.end();
  it--;
  int last_element = *it;
  it--;
  int second_last_element = *it;
  int val1 = second_last_element-first_element;
  int val2 = last_element-second_element;
  cout<<min(val1,val2);
  return 0;
}
