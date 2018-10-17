#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
    	vector<long> vv(n);
    	for(int i=0;i<n;i++)
    	{
    		cin>>vv[i];
    	}
    	sort(vv.begin(),vv.end(),greater<long>());
    	int ans=k;
    	int i=k-1;
    	long x=vv[i];
    	while(i<n && x==vv[i])
    	{
    		ans++;
    		i++;
    	}
    	ans-=1;
    	cout<<ans<<endl;
	}
return 0;
}
