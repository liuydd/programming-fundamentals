#include<iostream>
using namespace std;
long long int dp[100010]; //最后的三个点不过是因为没有用long long，因为相加的话可能超出int的范围
long long int d[100010];
int main(){
    long long int n;
    cin>>n;
    long long int a[100010];
    for(int i=0;i<100010;i++)
        a[i]=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
        cout<<a[0]<<endl;
    else if(n==2)
        cout<<max(a[0],a[1])<<endl;
    else if(n==3)
        cout<<max(max(a[0],a[1]),a[2])<<endl;
    else{
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    long long int res=0;
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    res=dp[n-2];
    d[0]=a[1];
    d[1]=max(a[1],a[2]);
    for(int i=2;i<n-1;i++){
        d[i]=max(d[i-1],d[i-2]+a[i+1]);
    }
    if(d[n-2]>res)
        res=d[n-2];
    cout<<res<<endl;
    }
    return 0;
}