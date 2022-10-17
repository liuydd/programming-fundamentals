#include<iostream>
#include<cmath>
using namespace std;
void ss(int n){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            cout<<i<<endl;
            n/=i;
        }
    }
    if(n!=1)
        cout<<n;
}
int count(int n,int k){
    int c=0;
    while(n!=1){
    if(n%k==0){
        n/=k;
        c++;
    }
    else
        break;
    }
    return c;
}
int main(){
    int n;
    bool flag=false;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++){  //这个要把两个for循环都改为根号n，否则时间复杂度还是O(n)
        if(count(n,i)>1)
            flag=true;
    }
    if(flag==true)
        cout<<'B'<<endl;
    else
        cout<<'A'<<endl;
    ss(n);
    return 0;
}