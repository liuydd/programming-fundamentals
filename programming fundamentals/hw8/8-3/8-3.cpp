#include<iostream>
using namespace std;
int main(){
    int n;
    int a[1010];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n];
    dp[0]=1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(res<dp[i])
            res=dp[i];
    }
    cout<<res<<endl;
    return 0;
}