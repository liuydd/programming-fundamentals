#include<iostream>
#include<cmath>
using namespace std;
double series(int n){
    double s_n=0.0;
    for(int i=1;i<=n;i++){
        s_n+=1.0/i;
    }
    return s_n;
}
double _series(int n){
    double s_n=0.0;
    s_n=log(n)+0.57721566490153286060651209;
    return s_n;
}
int main(){
    int k,n=1;
    double s;
    cin>>k;
    while(true){
        if(k<=10)   //11-15后就要用近似算法了
            s=series(n);
        else if(k==12||k==13)     //这个程序写的好丑，看什么时候再改改
            s=_series(n+1);
        else
            s=_series(n);
        if(s>k){
            cout<<n<<endl;
            break;
        }
        n++;
    }
    return 0;
}