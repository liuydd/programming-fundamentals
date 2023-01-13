#include<iostream>
using namespace std;
int det(int n,int a[7][7]);
int formula(int n,int a[7][7],int i,int j); //i和j为元素所在的行和列
int det(int n,int a[7][7]){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=formula(n,a,1,i+1)*a[0][i];
    }
    return sum;
}
int formula(int n,int a[7][7],int p,int q){
    int k=0,x=0;
    int sum=0;
    if(n==1)
        sum=1;
    else if(n==2)
        sum=a[2-p][2-q];
    else{
    int b[7][7];
    for(int i=0;i<n;i++){
        if(i==p-1)
            continue;
        x=0;
        for(int j=0;j<n;j++){
            if(j==q-1)
                continue;
            b[k][x]=a[i][j];
            x++;
        }
        k++;
    }
    sum+=det(n-1,b);
    }
    if((p+q)%2!=0){
        //cout<<1<<endl;
        sum*=-1;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int a[7][7];
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++)
            a[i][j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<det(n,a);
    return 0;
}