#include<iostream>
using namespace std;
int a[2020];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long int dp[2020];
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]&&dp[j]+a[i]>dp[i])
                dp[i]=dp[j]+a[i];
        }
    }
    int res=dp[0];
    for(int i=0;i<n;i++){
        if(dp[i]>res)
            res=dp[i];
    }
    cout<<res<<endl;
        //cout<<dp[i]<<" ";
    //cout<<endl;
    //cout<<dp[n-1]<<endl;
    return 0;
}