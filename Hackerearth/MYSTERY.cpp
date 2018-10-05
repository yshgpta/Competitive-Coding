#include<bits/stdc++.h>
using namespace std;

int main()
{
int t,n,c;
cin>>t;
while(t--){
cin>>n;
c=0;

for(int i=1;i<=sqrt(n);i++)
if(n%i==0)
c++;

if(n==0||n==1)
cout<<n<<"\n";
else{
int s=sqrt(n);
if(s*s==n)
cout<<2*c-1<<"\n";
else
cout<<2*c<<"\n";
}
}
return 0;
}
