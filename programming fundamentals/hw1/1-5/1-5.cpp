#include<iostream>
using namespace std;
int count_2(int num){
    int sum=0;
    while(true){
    if(num/10==0){
        if(num%10==2)
            sum++;
        break;
    }
    else{
        if(num%10==2)
            sum++;
        num/=10;
    }
    }
    return sum;
}
int main(){
    int l,r;
    cin>>l>>r;
    int restore=0;
    for(int i=l;i<=r;i++){
        restore+=count_2(i);
    }
    cout<<restore<<endl;
    return 0;
}