#include<iostream>
using namespace std;
int divide(int p,int q){
    int f[210][10];
    for(int i=1;i<=p;i++){
        f[i][0]=0;
        f[i][1]=1;
    }
    for(int i=2;i<=q;i++){
        f[0][i]=0;
        f[1][i]=0;
    }
    for(int i=2;i<=p;i++){
        for(int j=2;j<=q;j++){
            if(j>i)
                f[i][j]=0;
            else{
                f[i][j]=f[i-1][j-1]+f[i-j][j];;
            }
        }
    }
    return f[p][q];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<divide(n,k);
    return 0;
}