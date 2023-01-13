#include<iostream>
using namespace std;
const int p=100;



int main(){
    int n;
    cin>>n;
    int a[p]={},b[p]={};
    //int count=n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //b[i]=a[i];
    }
    //去重
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                //count--;
                for(int k=j;k<n;k++){
                    a[k]=a[k+1];
                }
                n-=1;
                j-=1;
            }
        }
    }
    //冒泡排序
    for(int i=0;i<n;i++){
       for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
       }
    }

    cout<<n<<endl;  //数量
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }



    return 0;
}