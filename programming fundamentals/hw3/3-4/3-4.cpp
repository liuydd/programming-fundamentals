#include<iostream>
#include<cmath>
using namespace std;
bool prime_number(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}
bool palin_number(int n){
    int i=n;
    int m=0;
    while(i>0){
        m=m*10+i%10;
        i/=10;
    }
    return m==n;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(palin_number(i)&&prime_number(i))  
//回文数少于质数，所以这里把回文数的判断放在前面，这样一旦不是回文数，则也就不用继续判断是否为质数了
            cout<<i<<endl;
    }
    return 0;
}