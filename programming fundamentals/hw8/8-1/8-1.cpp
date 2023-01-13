#include<iostream>
using namespace std;
int a[50000];
/*
int sum(int *a,int p,int q){
    int s=0;
    for(int i=p;i<=q;i++){
        s+=a[i];
    }
    return s;
}
*/
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n];
    int result=a[0];
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        dp[i]=max(a[i],dp[i-1]+a[i]);
        result=max(result,dp[i]);
    }
    cout<<result<<endl;
    return 0;
}