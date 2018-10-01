#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long int tc,a,b,k,d;
    cin>>tc;
    while(tc--)
    {
        cin>>k;
        d=sqrt(k);
        d=d*d;
        if(d!=k)
        cout<<"-1"<<endl;
        else
        {
        a=sqrt(k);
        b=a*a*a;
        cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
