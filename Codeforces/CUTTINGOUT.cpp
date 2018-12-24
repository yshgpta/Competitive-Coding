#include<bits/stdc++.h>
#define X 200005
using namespace std;

int arr[X+10],brr[X+10];
vector<pair<int,int> >crr;
int n,k;

bool check(int mid)
{
    int counter=0,i;
    for(i=0;i<crr.size();i++)
    {
        counter+=(crr[i].first/mid);
    }
    if(counter>=k) return 1;
    else return 0;
}


int bs()
{
    int low=1,high=100000000,mid,i,maxi=0;
    for(i=0;i<500;i++)
    {
        mid=(low+high)/2;
        if(check(mid)==true)
        {
            low=mid;
        }
        else
        {
            high=mid-1;
        }
        cerr<<"A "<<low<<" "<<high<<" "<<mid<<endl;
    }
    if(check(high)==true) maxi=max(maxi,high);
    if(check(low)==true) maxi=max(maxi,low);
    return maxi;
}


int main()
{
    ios::sync_with_stdio(false);
    int i,temp,counter;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        brr[arr[i]]++;
    }
    for(i=0;i<=X;i++)
    {
        if(brr[i])
        {
            crr.push_back({brr[i],i});
        }
    }
    sort(crr.begin(),crr.end(),greater<pair<int,int> >());
    temp=bs();
    counter=0;
    for(i=0;i<crr.size() and counter<k;i++)
    {
        while(crr[i].first>=temp and counter<k)
        {
            crr[i].first-=temp;
            cout<<crr[i].second<<" ";
            counter++;
        }
    }
    cout<<endl;
    return 0;
}
