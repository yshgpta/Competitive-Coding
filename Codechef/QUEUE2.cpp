#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,l;
    long k;
    cin>>n>>m>>k>>l;
    vector<long> A(n);
    for(int i=0;i<n;i++)
    {
      cin>>A[i];
    }
    sort(A.begin(),A.end());
    long B[n];
    B[0]=(m+1)*l;
    for(int i=1;i<n;i++)
    {
      B[i]=B[i-1]+l;
    }
    long C[n];
    for(int i=0;i<n;i++)
    {
      C[i]=B[i]-A[i];
    }
    long ans=*min_element(C,C+n);
    vector<long>::iterator it=lower_bound(A.begin(),A.end(),k);
    if(it==A.end())
    {
      long Bk=B[n-1]+l;
      long diffk=Bk-k;
      ans=min(ans,diffk);
    }
    else
    {
      long ind=it-A.begin();
      long Bk=B[ind];
      long diffk=Bk-k;
      ans=min(ans,diffk);
    }
    cout<<ans<<endl;
  }
return 0;
}
