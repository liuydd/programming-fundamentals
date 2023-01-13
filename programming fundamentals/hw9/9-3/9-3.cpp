#include<iostream>
using namespace std;
bool dp[60][1010];
int main(){
    int n,begin,max;
    int c[60];
    for(int i=0;i<60;i++)
        c[i]=0;
    cin>>n>>begin>>max;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    dp[0][begin]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=max;j++){
            if(dp[i-1][j]){
                if(j+c[i]<=max) dp[i][j+c[i]]=1;
                if(j-c[i]>=0) dp[i][j-c[i]]=1;
            }
        }
    }
    int res=-1;
    for(int i=0;i<=max;i++){
        if(dp[n][i])
            res=i;
    }
    cout<<res<<endl;
    return 0;
}