#include<iostream>
using namespace std;
int dp[1010][1010];
int main(){
    int n;
    int a[1010];
    cin>>n;
    for(int i=0;i<1010;i++)
        a[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int len=2;len<=n;len++){ //长度
        for(int i=1;i+len-1<=n;i++){ //起点
            int j=i+len-1; //终点
            dp[i][j]=1e8;
            for(int k=i;k<j;k++){ //遍历起点到终点
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[j]-a[i-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}