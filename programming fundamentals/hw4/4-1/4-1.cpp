#include<iostream>
using namespace std;
const int p=100000;
int main(){
    int n;
    int a[p],b[p],x[p],y[p];
    //int flag[10000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>x[i]>>y[i];
        //flag[i]=i;
    }
    int u,v;
    cin>>u>>v;
    int flag=0;
    for(int k=n;k>0;k--){
        if(u>=a[k]&&u<=(a[k]+x[k])&&v>=b[k]&&v<=(b[k]+y[k])){
            flag=1;
            cout<<k;
            break;
        }
    }
    if(flag==0)
        cout<<"-1";
    return 0;
}