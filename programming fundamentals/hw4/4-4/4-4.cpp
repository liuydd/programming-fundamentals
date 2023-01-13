#include<iostream>
using namespace std;
int main(){
    int m,n;
    int max=-2000000;  //这里不能将max初始化为0，因为可能全为负数！
    cin>>n>>m;
    int matrix[100][100]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]>=max)
                max=matrix[i][j];
        }
    }
    //预处理：从左上角顶点到[i][j]
    int sum[100][100]={};
    sum[0][0]=matrix[0][0];
    for(int i=1;i<m;i++){
        sum[0][i]=sum[0][i-1]+matrix[0][i];
    }
    
    for(int j=1;j<n;j++){
        sum[j][0]=sum[j-1][0]+matrix[j][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
        }
    }
   
    //遍历所有子矩阵计算和的最大值
    int s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int p=i;p<n;p++){
                for(int q=j;q<m;q++){
                    if(i>=1&&j>=1){
                        s=sum[p][q]-sum[p][j-1]-sum[i-1][q]+sum[i-1][j-1];
                    }
                    else if(i==0&&j>=1){
                        s=sum[p][q]-sum[p][j-1];
                    }
                    else if(j==0&&i>=1){
                        s=sum[p][q]-sum[i-1][q];
                    }
                    else{
                        s=sum[p][q];
                    }
                    if(s>=max)
                        max=s;
                }
            }
        }
    }
    
    cout<<max;
    
    return 0;
}