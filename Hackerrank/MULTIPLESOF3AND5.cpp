#include<bits/stdc++.h>
using namespace std;
long long result(long n){
    long long sum=0,rem;
    if(n<=3)
        return 0;
    else{
        rem=(n-1)/3;
        sum+=3*rem*(rem+1)/2;
    }
    if(n<=5)
        return sum;
    else{
        rem=(n-1)/5;
        sum+=5*rem*(rem+1)/2;
    }
    if(n<=15)
    return sum;
    else{
        rem=(n-1)/15;
        sum-=15*rem*(rem+1)/2;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        cout<<result(n)<<endl;
    }
    return 0;
}
