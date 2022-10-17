#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int change(int n){
    int a1,a2,a3,a4;
    a1=n%10;
    n/=10;
    a2=n%10;
    n/=10;
    a3=n%10;
    a4=n/10;
    int a[4]={a1,a2,a3,a4};
    sort(a,a+4);
    int b;
    b=a[0]*1000+a[1]*100+a[2]*10+a[3];
    //cout<<b<<endl;
    sort(a,a+4,greater<int>());
    int c;
    c=a[0]*1000+a[1]*100+a[2]*10+a[3];
    //cout<<c<<endl;
    return c-b;
}

int main(){
    int n;
    cin>>n;
    int count=0;
    while(change(n)!=6174){
        n=change(n);
        count++;
    }
    cout<<count+1;
    return 0;
}