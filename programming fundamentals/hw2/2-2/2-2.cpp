#include<iostream>
using namespace std;
const int p=1000000007;
int fib(int n){
    int f,f1=1,f2=1;
    if(n==1||n==2){
        f=1;
        return f;
    }
    else if(n>2)
        for(int i=3;i<=n;i++){
            f=f1+f2;
            f1=f2;
            f2=f;
        }
        //cout<<f2<<endl;
        return f2;
}
int sum(int n){
    int s;
    if(n%3==1)
        s=1;
    else if(n%3==2){
        //s=s%p;
        s=1+fib(n);
    }
    else{
        //s=s%p;
        s=1+fib(n)+fib(n-1);
    }
    return s;
}
int main(){
    int n,s;
    cin>>n;
    
    cout<<sum(n)%p<<endl;
    return 0;
}